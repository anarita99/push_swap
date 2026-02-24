# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adores <adores@student.42lisboa.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/11 15:03:19 by adores            #+#    #+#              #
#    Updated: 2025/06/16 11:12:43 by adores           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC := assign.c list_op.c parsing.c push_op.c push_swap.c revrot_op.c rotate_op.c \
	sort_small.c swap_op.c radix_sort.c sort_5.c

OBJ := $(SRC:.c=.o)

INC := push_swap.h

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re