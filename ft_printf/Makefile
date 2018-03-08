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

SRCS = ft_printf.c ft_unicode.c

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
	gcc main.c libftprintf.a 

norm:
	norminette -R CheckForbiddenSourceHeader

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re: fclean all


