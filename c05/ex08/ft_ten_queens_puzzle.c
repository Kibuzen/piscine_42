/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 10:12:31 by qujacob           #+#    #+#             */
/*   Updated: 2021/02/10 11:18:55 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_solution(int ch_plate[10][10])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 10)
	{
		while (j < 10)
		{
			if (ch_plate[i][j] == 1)
				ft_putchar(j + '0');
			j++;
		}
		i++;
		j = 0;
	}
	ft_putchar('\n');
}

int		avoiding_collision(int ch_plate[10][10], int line, int col)
{
	int i;
	int j;

	i = -1;
	while (++i < 10)
		if (ch_plate[i][col] == 1)
			return (0);
	i = -1;
	while (++i < 10)
		if (ch_plate[line][i] == 1)
			return (0);
	i = line;
	j = col;
	while (--i > -1 && --j > -1)
		if (ch_plate[i][j] == 1)
			return (0);
	i = line;
	j = col;
	while (--i > -1 && ++j < 10)
		if (ch_plate[i][j] == 1)
			return (0);
	return (1);
}

int		recursive_search(int ch_plate[10][10], int line, int col, int *count)
{
	int i;

	i = 0;
	if (line > 9)
	{
		print_solution(ch_plate);
		recursive_search(ch_plate, 0, col + 1, count);
		*count += 1;
	}
	while (i < 10)
	{
		if (avoiding_collision(ch_plate, line, i))
		{
			ch_plate[line][i] = 1;
			if (recursive_search(ch_plate, line + 1, col, count))
				return (1);
			ch_plate[line][i] = 0;
		}
		i++;
	}
	return (0);
}

int		ft_ten_queens_puzzle(void)
{
	int ch_plate[10][10];
	int line;
	int col;
	int count;

	count = 0;
	line = -1;
	while (++line < 10)
	{
		col = -1;
		while (++col < 10)
			ch_plate[line][col] = 0;
	}
	recursive_search(ch_plate, 0, 0, &count);
	return (count);
}
