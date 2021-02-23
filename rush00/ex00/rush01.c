/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 09:34:54 by fbertran          #+#    #+#             */
/*   Updated: 2021/02/06 15:19:55 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	affichage(int i, int j, int x, int y)
{
	if (x == 1 && y == 1)
		ft_putchar('/');
	else if ((x == 1 && i == y - 1) || (y == 1 && j == x - 1))
		ft_putchar('\\');
	else if ((j == 0 && i == 0) || (j == x - 1 && i == y - 1))
		ft_putchar('/');
	else if ((j == x - 1 && i == 0) || (j == 0 && i == y - 1))
		ft_putchar('\\');
	else if (j == 0 || j == x - 1 || i == 0 || i == y - 1)
		ft_putchar('*');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int i;
	int j;

	if (x > 0 && y > 0)
	{
		i = 0;
		while (i < y)
		{
			j = 0;
			while (j < x)
			{
				affichage(i, j, x, y);
				j++;
			}
			ft_putchar('\n');
			i++;
		}
	}
}
