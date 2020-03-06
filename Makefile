# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/02 16:45:56 by lbarthon          #+#    #+#              #
#    Updated: 2020/03/06 10:47:50 by lbarthon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CPPFLAGS=-I./libft/includes -I./includes/
CFLAGS=-Wall -Werror -Wextra
LDFLAGS=-Llibft -lft

NAME=ft_ssl

SRCDIR=./srcs/
SRCS=errors/usage.c \
	 errors/commands.c \
	 flags.c \
	 hash.c \
	 display.c \
	 md5/md5.c \
	 md5/md5_utils.c \
	 sha256/sha256.c \
	 sha256/sha256_utils.c \
	 utils/rotate.c \
	 utils/sha2_sig.c \
	 utils/sha2.c \
	 main.c

OBJDIR=.obj
OBJS=$(SRCS:.c=.o)
DEPS=$(SRCS:.c=.d)

LIBDIR=libft
LIB_NAME=$(LIBDIR)/libft.a

all: $(NAME)

$(NAME): $(LIB_NAME) $(addprefix $(OBJDIR)/,$(OBJS))
	$(CC) $(CFLAGS) -o $(NAME) $^

-include $(addprefix $(OBJDIR)/,$(DEPS))

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -MMD -o $@ -c $<

$(OBJDIR):
	@mkdir $@ 2> /dev/null || true
	@mkdir $@/md5 2> /dev/null || true
	@mkdir $@/sha256 2> /dev/null || true
	@mkdir $@/sha1 2> /dev/null || true
	@mkdir $@/errors 2> /dev/null || true
	@mkdir $@/utils 2> /dev/null || true

$(LIB_NAME):
	make -C $(LIBDIR)

fclean: clean
	rm -f $(NAME)
	make -C $(LIBDIR) fclean

clean:
	rm -rf $(OBJDIR)
	make -C $(LIBDIR) clean

re: fclean all

.PHONY: all fclean clean re
