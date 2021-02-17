/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 08:11:57 by qujacob           #+#    #+#             */
/*   Updated: 2021/02/10 15:07:35 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int x;

	x = 0;
	if (nb < 0)
		return (0);
	while (x <= 46340)
	{
		if (x * x == nb)
			return (x);
		x++;
	}
	return (0);
}
