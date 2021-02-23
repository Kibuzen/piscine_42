# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qujacob <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/17 10:02:58 by qujacob           #+#    #+#              #
#    Updated: 2021/02/17 10:27:42 by qujacob          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
BIN = do-op
SRCS = main.c ft_atoi.c ft_operations.c ft_putnbr.c ft_strcmp.c
OBJS =$(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror

all: $(OBJS)
	$(CC) $^ -o $(BIN) -I .

.c.o:
	$(CC) $(FLAGS) -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(BIN)

re: fclean all
