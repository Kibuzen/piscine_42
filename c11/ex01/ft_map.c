/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:03:59 by qujacob           #+#    #+#             */
/*   Updated: 2021/02/19 16:16:38 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int		*dest;
	int		i;

	dest = (int *)malloc(sizeof(int) * length);
	if (dest == NULL)
		return (NULL);
	i = -1;
	while (++i < length)
		dest[i] = f(tab[i]);
	return (dest);
}
