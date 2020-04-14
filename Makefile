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

INC = ./headers/

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJ) $(INC)*
	make -C $(LIBFT)
	cp libft/libft.a $(NAME)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "made libftprintf"

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJ): $(OBJDIR)%.o : $(SRCDIR)%.c ./headers/*.h
	@gcc $(FLAGS) -I $(INC) -I ./libft/includes/ -c $< -o $@

norm:
	norminette -R CheckForbiddenSourceHeader

clean:
	rm -rf $(OBJDIR)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re: fclean all


