#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vblokha <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/04 16:49:00 by vblokha           #+#    #+#              #
#    Updated: 2018/03/04 16:49:02 by vblokha          ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAME = libftprintf.a

LIBFT = libft

SRCS = ft_printf.c unicode.c first_modifier.c flags.c help_to_show.c \
help_width_precision.c help.c lst_to_show.c result_show.c second_modifier.c \
first_set.c second_set.c struct_show.c type_show.c unicode_width.c

OBJ = ./$(SRCS:.c=.o)

INCLUDES = ft_printf.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT)
	cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o : %c
	gcc $(FLAGS) -I $(INCLUDES) -c $<

comp:
	gcc -g main.c ft_printf.c unicode.c first_modifier.c flags.c help_to_show.c \
help_width_precision.c help.c lst_to_show.c result_show.c second_modifier.c \
first_set.c second_set.c struct_show.c type_show.c unicode_width.c libft/libft.a 

norm:
	norminette -R CheckForbiddenSourceHeader

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re: fclean all


