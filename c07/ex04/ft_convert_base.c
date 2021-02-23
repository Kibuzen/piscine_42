/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 11:39:06 by qujacob           #+#    #+#             */
/*   Updated: 2021/02/17 15:39:33 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
int		ft_isspace(char c);
int		check_error_base(char *base);
char	*check_in_base(char c, char *base);
int		ft_atoi_base(char *str, char *base);

int		count_digits(int nb, char *base)
{
	if (nb == 0)
		return (1);
	else
		return (1 + count_digits(nb / ft_strlen(base), base));
}

char	*ft_strrev(char *str)
{
	char	*copy;
	int		i;
	int		j;

	copy = (char *)malloc(sizeof(char) * (ft_strlen(str)));
	if (copy == NULL)
		return (NULL);
	i = 0;
	j = ft_strlen(str) - 1;
	while (i < ft_strlen(str))
	{
		copy[i] = str[j];
		i++;
		j--;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_itoa_base(int nb, char *base)
{
	int		nb_digits;
	char	*final_nbr;
	int		i;
	int		negative;
	long	nbr;

	nbr = (long)nb;
	nb_digits = count_digits(nbr, base);
	if (!(final_nbr = (char *)malloc(sizeof(char) * (nb_digits + 1))))
		return (NULL);
	if (nbr < 0)
	{
		negative = 1;
		nbr *= -1;
	}
	i = -1;
	while (++i < nb_digits - 1)
	{
		final_nbr[i] = base[nbr % ft_strlen(base)];
		nbr = nbr / ft_strlen(base);
	}
	if (negative == 1)
		final_nbr[i++] = '-';
	final_nbr[i] = '\0';
	return (final_nbr);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb;
	char	*final_nb;

	if (check_error_base(base_from) || check_error_base(base_to))
		return (NULL);
	nb = ft_atoi_base(nbr, base_from);
	if (nb == 0)
	{
		final_nb = (char *)malloc(sizeof(char) * 2);
		if (final_nb == NULL)
			return (NULL);
		final_nb[0] = base_to[0];
		final_nb[1] = '\0';
		return (final_nb);
	}
	final_nb = ft_itoa_base(nb, base_to);
	return (ft_strrev(final_nb));
}
