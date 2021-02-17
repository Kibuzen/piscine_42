/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 08:27:48 by qujacob           #+#    #+#             */
/*   Updated: 2021/02/09 12:03:37 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	hexadecimal(char c)
{
	char h1;
	char h2;

	write(1, "\\", 1);
	h1 = c / 16;
	h2 = c % 16;
	if (h1 < 10)
		h1 += '0';
	else
		h1 += 87;
	if (h2 < 10)
		h2 += '0';
	else
		h2 += 87;
	write(1, &h1, 1);
	write(1, &h2, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] <= 31 || (unsigned char)str[i] >= 127)
			hexadecimal(str[i]);
		else
			write(1, &str[i], 1);
		i++;
	}
}
