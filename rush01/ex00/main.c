/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 08:55:48 by qujacob           #+#    #+#             */
/*   Updated: 2021/02/14 16:14:29 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"
#include "ft_error.h"

void	print_solution(int board[4][4])
{
	int i;
	int j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			ft_putnbr(board[i][j]);
			if (j != 3)
				ft_putstr(" ");
		}
		ft_putstr("\n");
	}
}

int		avoiding_constraints(int *tab, int board[4][4], int line, int col)
{
	(void)tab;
	(void)board;
	(void)line;
	(void)col;
	return (1);
}

int		recursive_search(int *tab, int board[4][4], int line, int col)
{
	int nb;

	if (line == 4)
	{
		print_solution(board);
		return (1);
	}
	if (col == 4)
	{
		recursive_search(tab, board, line + 1, 0);
		return (1);
	}
	nb = 0;
	while (++nb <= 4)
	{
		if (avoiding_constraints(tab, board, line, col))
		{
			board[line][col] = nb;
			if (recursive_search(tab, board, line, col + 1))
				return (1);
			board[line][col] = 0;
		}
	}
	return (0);
}

int		ft_skyscrapers(int *tab)
{
	int board[4][4];
	int i;
	int j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			board[i][j] = 0;
	}
	if (recursive_search(tab, board, 0, 0))
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	int *tab;

	(void)av;
	if (ac != 2)
	{
		ft_putstr_error("Error : Program must have 1 argument.\n");
		return (0);
	}
	tab = ft_parse(av[1]);
	if (tab == 0)
	{
		ft_putstr_error("Error : You should write only 16 numbers between 1\
		and 4.\n");
		return (0);
	}
	if (ft_skyscrapers(tab) == 0)
		ft_putstr_error("Error : This board is not playable.\n");
	return (0);
}
