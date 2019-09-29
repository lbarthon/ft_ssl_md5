# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/02 16:45:56 by lbarthon          #+#    #+#              #
#    Updated: 2019/09/29 13:44:01 by lbarthon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=@gcc
CFLAGS=-g -Wall -Werror -Wextra -I includes
#CFLAGS=-g  -I includes

NAME=ft_ssl
SRCS=./srcs/lib/ft_putstr.c \
	 ./srcs/lib/ft_strcmp.c \
	 ./srcs/lib/ft_strnew.c \
	 ./srcs/lib/ft_memrev.c \
	 ./srcs/lib/files.c \
	 ./srcs/errors/usage.c \
	 ./srcs/errors/commands.c \
	 ./srcs/commands.c \
	 ./srcs/flags.c \
	 ./srcs/hash.c \
	 ./srcs/md5/md5.c \
	 ./srcs/md5/md5_utils.c \
	 ./srcs/md5/md5_display.c \
	 ./srcs/sha256/sha256.c \
	 ./srcs/sha256/sha256_utils.c \
	 ./srcs/sha256/sha256_display.c \
	 ./srcs/main.c

OBJS=$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

fclean: clean
	@rm -f $(NAME)

clean:
	@rm -rf $(OBJS)

re: fclean all

.PHONY: all fclean clean re
