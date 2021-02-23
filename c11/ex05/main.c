/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 10:03:17 by qujacob           #+#    #+#             */
/*   Updated: 2021/02/19 16:38:50 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_operation(void (*c[5])(int, int), int a, int b, char *op)
{
	if (!ft_strcmp(op, "+"))
		c[0](a, b);
	else if (!ft_strcmp(op, "-"))
		c[1](a, b);
	else if (!ft_strcmp(op, "*"))
		c[2](a, b);
	else if (!ft_strcmp(op, "/"))
		c[3](a, b);
	else if (!ft_strcmp(op, "%"))
		c[4](a, b);
	else
		ft_putnbr(0);
}

int		main(int ac, char *av[])
{
	int		a;
	int		b;
	void	(*calculate[5])(int, int);

	if (ac == 4)
	{
		a = ft_atoi(av[1]);
		b = ft_atoi(av[3]);
		calculate[0] = &ft_add;
		calculate[1] = &ft_sub;
		calculate[2] = &ft_mul;
		calculate[3] = &ft_div;
		calculate[4] = &ft_mod;
		ft_operation(calculate, a, b, av[2]);
		ft_putstr("\n");
	}
	return (0);
}
