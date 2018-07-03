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

SRC = ft_printf.c unicode.c first_modifier.c flags.c help_to_show.c \
help_width_precision.c help.c lst_to_show.c result_show.c second_modifier.c \
first_set.c second_set.c struct_show.c type_show.c unicode_width.c

SRCDIR = sources/

OBJDIR = objects/

OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))

INC = headers/ft_printf.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJDIR) $(LIBFT)  $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(LIBFT):
	@echo make libft
	make -C $(LIBFT)
	cp libft/libft.a ./$(NAME)

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJ): $(OBJDIR)%.o : $(SRCDIR)%.c
	gcc $(FLAGS) -I $(INC) -c $< -o $@

norm:
	norminette -R CheckForbiddenSourceHeader

clean:
	rm -rf $(OBJDIR)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re: fclean all


