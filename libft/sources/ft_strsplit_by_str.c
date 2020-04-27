#include "libft.h"

static char		**ft_new_double_chr_arr(const size_t size_y, const size_t full_size)
{
	char	**double_arr;

	if (!(double_arr = ft_memalloc(sizeof(char*) * (size_y + 1))))
		return (NULL);
	if (!full_size && (!(double_arr[0] = ft_memalloc(full_size))))
		return (NULL);
	return double_arr;
}

static size_t	count_not_delims(const char *str, const char *delimiters)
{
	size_t i;
	size_t count;

	count = i = 0;
	while (str[i])
	{
		if (ft_strchr(delimiters, str[i]))
			count++;
		i++;
	}
	return count;
}

static void	fill_divided_str_copy(const char *str, const char *delimiters,\
	char **filled_str)//'\0' instead of delimiters like "A\0BB\0CCC\0"
{
	size_t	i;
	size_t	j;
	bool	is_delim;

	i = j = 0;
	is_delim = true;
	while (str[i])
	{
		if (!ft_strchr(delimiters, str[i]))
		{
			filled_str[0][j++] = str[i];
			if (is_delim)
				is_delim = false;
		}
		else if (!is_delim)
		{
			filled_str[0][j++] = '\0';
			is_delim = true;
		}
		i++;
	}
}

static void	fill_split(char *str, char **split, const size_t n_words)
{
	size_t i_word ;
	size_t j;
	
	i_word = j = 1;
	while (i_word < n_words)
	{
		while (str[j] != '\0')
			j++;
		j++;
		split[i_word] = str + j;
		i_word++;
	}
	split[i_word] = NULL;
}

//split without memory fragmentation
char	**ft_strsplit_by_str(char const *str, const char *delimiters)
{
	char	**split;
	size_t	n_words;

	if (!str || !delimiters)
		return NULL;
	n_words = ft_count_words_by_delims(str, delimiters);
	split = ft_new_double_chr_arr(n_words, count_not_delims(str, delimiters) + n_words);
	fill_divided_str_copy(str, delimiters, &(split[0]));
	fill_split(split[0], split, n_words);
	return (split);
}