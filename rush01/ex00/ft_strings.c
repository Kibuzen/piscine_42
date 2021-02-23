/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-bels <hde-bels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 08:59:05 by qujacob           #+#    #+#             */
/*   Updated: 2021/02/14 15:47:05 by mtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int		count_words(char *str)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ' && str[i] != '\0')
			i++;
		if (str[i] != ' ' && str[i] != '\0')
		{
			count++;
			while (str[i] != ' ' && str[i] != '\0')
				i++;
		}
	}
	return (count);
}

int		*ft_parse(char *av)
{
	int i;
	int j;
	int *tab;

	tab = (int *)malloc(sizeof(int) * 16);
	if (tab == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (av[i] != '\0')
	{
		if (av[i] >= '1' && av[i] <= '4')
		{
			tab[j] = av[i] - '0';
			j++;
		}
		i++;
	}
	if (count_words(av) != 16 || j != 16 || ft_strlen(av) != 31)
		return (0);
	return (tab);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		ft_putstr("-2147483648");
	else
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			nb *= -1;
		}
		if (nb >= 10)
			ft_putnbr(nb / 10);
		nb %= 10;
		nb += '0';
		write(1, &nb, 1);
	}
}
