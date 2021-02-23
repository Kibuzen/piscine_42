# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qujacob <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/14 10:14:18 by qujacob           #+#    #+#              #
#    Updated: 2021/02/17 12:25:06 by qujacob          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c
INCDIR = includes/
OBJS = $(SRCS:.c=.o)
BIN = libft.a
FLAGS = -Wall -Wextra -Werror

all: $(BIN)

.c.o:
	gcc $(FLAGS) -I $(INCDIR) -c $< -o $(<:.c=.o) 

$(BIN): $(OBJS)
	ar rc $(BIN) $(OBJS)
	ranlib $(BIN)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(BIN)

re: fclean all

.PHONY: all clean fclean re
