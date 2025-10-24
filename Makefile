# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmanani <jmanani@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/24 14:12:49 by jmanani           #+#    #+#              #
#    Updated: 2025/10/24 15:17:32 by jmanani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= cc
CFLAGS= -Wall -Wextra -Werror
RM= rm -f

NAME= libftprintf.a

LIBFT_FOLDER= libft

SRCS = ft_printf.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_FOLDER)
	ar rcs $(NAME) $(OBJS)

clean:
	make -C $(LIBFT_FOLDER) clean
	$(RM) $(OBJS)

fclean:
	make -C $(LIBFT_FOLDER) fclean
	make clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re