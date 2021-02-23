/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 08:28:25 by qujacob           #+#    #+#             */
/*   Updated: 2021/02/23 08:50:50 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort_left(int *tab, int length, int (*f)(int, int))
{
	int i;

	i = 1;
	while (i < length)
	{
		if (f(tab[i - 1], tab[i]) > 0)
			return (0);
		i++;
	}
	return (1);
}

int		ft_is_sort_right(int *tab, int length, int (*f)(int, int))
{
	int i;

	i = length - 2;
	while (i >= 0)
	{
		if (f(tab[i + 1], tab[i]) > 0)
			return (0);
		i--;
	}
	return (1);
}

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	if (ft_is_sort_left(tab, length, f) || ft_is_sort_right(tab, length, f))
		return (1);
	return (0);
}
