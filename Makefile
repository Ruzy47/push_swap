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

BUILD =	build

CC = cc

SRC = $(wildcard ps/*.c)

SRCB = $(wildcard ps_b/*.c)

LIBFT = libft

OBJ = $(patsubst %.c, %.o, $(SRC))
OBJB = $(patsubst %.c, %.o, $(SRCB))

A = $(patsubst %.o, $(BUILD)/%.o, $(OBJ))
B = $(patsubst %.o, $(BUILD)/%.o, $(OBJB))

CFLAGS = -Wall -Wextra -Werror

$(BUILD)/%.o: %.c Makefile
	@mkdir -p $(BUILD)/ps
	@mkdir -p $(BUILD)/ps_b
	$(CC) -c $(CFLAGS) $< -o $@

all: $(NAME)

$(NAME): $(A)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) $(A) -o $(NAME) -L./libft -lft

$(BONUS): $(B)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) $(B) -o $(BONUS) -L./libft -lft

bonus: $(NAME) $(BONUS)


fclean: clean
	rm -rf $(NAME) $(BONUS) $(BUILD)

clean:
	$(MAKE) clean -C $(LIBFT)
	rm -rf $(OBJ) $(OBJB)

re: fclean all

.PHONY: all clean fclean re bonus
