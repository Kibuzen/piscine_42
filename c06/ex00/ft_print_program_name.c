/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 08:46:02 by qujacob           #+#    #+#             */
/*   Updated: 2021/02/09 09:49:45 by qujacob          ###   ########.fr       */
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
	(void)argc;
	ft_putstr(argv[0]);
	ft_putstr("\n");
	return (0);
}
