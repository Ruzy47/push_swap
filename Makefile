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

BONUS = checker

BUILD =	./build

CC = cc

SRC = 	ps/main.c		\
		ps/errors.c		\
		ps/rules.c		\
		ps/rules2.c		\
		ps/parsing.c	\
		ps/butterfly.c	\
		ps/litfly.c		\

SRCB =	ps_b/main.c							\
		ps_b/errors.c						\
		ps_b/rules.c						\
		ps_b/rules2.c						\
		ps_b/parsing.c						\
		ps_b/butterfly.c					\
		ps_b/litfly.c						\
		ps_b/get_next_line_bonus.c			\
		ps_b/get_next_line_utils_bonus.c	\

LIBFT = libft

OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)

CFLAGS = -Wall -Wextra -Werror

$(BUILD)/%.o: $(SRC)/%.c Makefile
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILD)/%.o: $(SRCB)/%.c Makefile
	$(CC) -c $(CFLAGS) $< -o $@

all: $(BUILD) lib $(NAME)

$(BUILD):
	@mkdir $(BUILD)

lib:
	@make -C Libft

$(NAME): $(BUILD) $(OBJ)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L./libft -lft

$(BONUS): $(BUILD) $(OBJB)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJB) -o $(NAME) -L./libft -lft

bonus:
	$(BUILD) lib $(BONUS)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(BONUS)
	rm -rf $(BUILD)

clean:
	$(MAKE) clean -C $(LIBFT)
	rm -rf $(OBJ)
	rm -rf $(OBJB)

re: fclean all bonus

.PHONY: all clean fclean re bonus
