# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rugrigor <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 14:08:11 by rugrigor          #+#    #+#              #
#    Updated: 2023/04/17 19:00:36 by rugrigor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

SRC = 	ps/main.c		\
		ps/errors.c		\
		ps/rules.c		\
		ps/rules2.c		\
		ps/parsing.c	\
		ps/butterfly.c	\
		ps/litfly.c		\

SRCB =	ps/main.c		\
		ps/errors.c		\
		ps/rules.c		\
		ps/rules2.c		\
		ps/parsing.c	\
		ps/butterfly.c	\
		ps/litfly.c		\

LIBFT = libft

OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)

CFLAGS = -g -Wall -Wextra -Werror -fsanitize=address

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L./libft -lft

bonus: $(OBJB)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJB) -o $(NAME) -L./libft -lft

%.o: %.c Makefile
	$(CC) -c $(CFLAGS) $< -o $@

fclean: clean
	rm -rf $(NAME) 

clean:
	$(MAKE) clean -C $(LIBFT)
	rm -rf $(OBJ)
	rm -rf $(OBJB)

re: fclean all

.PHONY: all clean fclean re bonus
