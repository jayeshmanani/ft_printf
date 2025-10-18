# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmanani <jmanani@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/18 19:00:38 by jmanani           #+#    #+#              #
#    Updated: 2025/10/18 19:57:18 by jmanani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= cc
CFLAGS= -Wall -Wextra -Werror

NAME= libft.a

SOURCES= ft_atoi.c ft_isalpha.c ft_itoa.c ft_memmove.c ft_putnbr_fd.c \
			ft_strdup.c ft_strlcpy.c ft_strnstr.c ft_tolower.c ft_bzero.c \
			ft_isascii.c ft_memchr.c ft_memset.c ft_putstr_fd.c ft_striteri.c \
			ft_strlen.c ft_strrchr.c ft_toupper.c ft_calloc.c ft_isdigit.c \
			ft_memcmp.c ft_putchar_fd.c ft_split.c ft_strjoin.c ft_strmapi.c \
			ft_strtrim.c ft_isalnum.c ft_isprint.c ft_memcpy.c ft_putendl_fd.c \
			ft_strchr.c ft_strlcat.c ft_strncmp.c ft_substr.c

BONUS= ft_lstnew.c

OBJS= $(SOURCES:.c=.o)

BONUS_OBJS= $(BONUS:.c=.o)

all: $(NAME) 

$(NAME): $(OBJS)
	ar rcs $@ $(OBJS)

bonus:	$(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus