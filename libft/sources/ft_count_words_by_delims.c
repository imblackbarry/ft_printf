#include "libft.h"

size_t	ft_count_words_by_delims(const char *str, const char *delimiters)
{
	size_t i;
	size_t n_words;
	bool is_inside_word;

	if (!str || !delimiters)
		return 0;
	i = n_words = is_inside_word = 0;
	while (str[i])
		if (ft_strchr(delimiters, str[i++]))
		{
			if (is_inside_word)
				is_inside_word = false;
		}
		else if (!is_inside_word)
		{
			is_inside_word = true;
			n_words++;
		}
	return (n_words);
}