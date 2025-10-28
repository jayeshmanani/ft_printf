# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmanani <jmanani@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/24 14:12:49 by jmanani           #+#    #+#              #
#    Updated: 2025/10/28 14:15:24 by jmanani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= cc
CFLAGS= -Wall -Wextra -Werror
RM= rm -f

NAME= libftprintf.a
LIBFT_NAME = libft.a

LIBFT_FOLDER= ./libft

SRCS = ft_printf.c handle_char.c handle_string.c\
		ft_count_digits.c ft_putnbr_base.c handle_numbers.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_FOLDER)
	mv $(LIBFT_FOLDER)/$(LIBFT_NAME) $(NAME)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT_FOLDER)

fclean:
	make clean
	$(RM) $(NAME)
	cd $(LIBFT_FOLDER) && $(RM) $(LIBFT_NAME)

re: fclean all

.PHONY: all clean fclean re