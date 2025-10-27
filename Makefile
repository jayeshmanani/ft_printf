# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmanani <jmanani@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/24 14:12:49 by jmanani           #+#    #+#              #
#    Updated: 2025/10/27 12:11:08 by jmanani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= cc
CFLAGS= -Wall -Wextra -Werror
RM= rm -f

NAME= libftprintf.a
LIBFT_NAME = libft.a

LIBFT_FOLDER= ./libft

SRCS = ft_printf.c handle_char.c handle_string.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): gen_libft $(OBJS)
	ar rcs $(NAME) $(OBJS)

gen_libft:
	make -C $(LIBFT_FOLDER)
	cp $(LIBFT_FOLDER)/$(LIBFT_NAME) .
	mv $(LIBFT_NAME) $(NAME)

clean:
	$(RM) $(OBJS)
	cd $(LIBFT_FOLDER) && make clean

fclean:
	make clean
	$(RM) $(NAME)
	cd $(LIBFT_FOLDER) && make fclean

re: fclean all

.PHONY: all clean fclean re