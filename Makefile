# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/02 16:45:56 by lbarthon          #+#    #+#              #
#    Updated: 2020/03/05 17:23:21 by lbarthon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-g -Wall -Werror -Wextra -I includes -I libft/includes
#CFLAGS=-g  -I includes

NAME=ft_ssl
SRCS=./srcs/errors/usage.c \
	 ./srcs/errors/commands.c \
	 ./srcs/flags.c \
	 ./srcs/hash.c \
	 ./srcs/display.c \
	 ./srcs/md5/md5.c \
	 ./srcs/md5/md5_utils.c \
	 ./srcs/sha256/sha256.c \
	 ./srcs/sha256/sha256_utils.c \
	 ./srcs/utils/rotate.c \
	 ./srcs/utils/sha2_sig.c \
	 ./srcs/utils/sha2.c \
	 ./srcs/main.c

OBJS=$(SRCS:.c=.o)
LIB_DIR=libft
LIB_NAME=$(LIB_DIR)/libft.a

all: $(NAME)

$(NAME): $(LIB_NAME) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $^

$(LIB_NAME):
	make -C $(LIB_DIR)

fclean: clean
	rm -f $(NAME)
	make -C $(LIB_DIR) fclean

clean:
	rm -rf $(OBJS)
	make -C $(LIB_DIR) clean

re: fclean all

.PHONY: all fclean clean re
