/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 08:50:31 by qujacob           #+#    #+#             */
/*   Updated: 2021/02/09 13:17:17 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		write(1, &str[i++], 1);
}

int		main(int argc, char *argv[])
{
	while (--argc > 0)
	{
		ft_putstr(argv[argc]);
		ft_putstr("\n");
	}
	return (0);
}
