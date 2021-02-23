/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 08:14:23 by qujacob           #+#    #+#             */
/*   Updated: 2021/02/15 14:28:59 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_a_charset(char *str, char *charset)
{
	int i;

	i = -1;
	while (charset[++i] != '\0')
		if (charset[i] == *str)
			return (1);
	return (0);
}

int		size(char *str, char *charset)
{
	int count;

	count = 0;
	while (!is_a_charset(str, charset) && *str)
	{
		count++;
		str++;
	}
	return (count);
}

int		count_words(char *str, char *charset)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (is_a_charset(&str[i], charset) && str[i] != '\0')
			i++;
		if (!is_a_charset(&str[i], charset) && str[i] != '\0')
		{
			count++;
			while (!is_a_charset(&str[i], charset) && str[i] != '\0')
				i++;
		}
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		nb_words;
	int		index;
	int		i;

	nb_words = count_words(str, charset);
	if (!(tab = (char **)malloc(sizeof(char *) * (nb_words + 1))))
		return (NULL);
	tab[nb_words] = 0;
	index = -1;
	while (++index < nb_words)
	{
		while (is_a_charset(str, charset) && *str != '\0')
			str++;
		tab[index] = (char *)malloc(sizeof(char) * (size(str, charset) + 1));
		if (tab == NULL)
			return (NULL);
		i = 0;
		while (*str && !is_a_charset(str, charset))
			tab[index][i++] = *str++;
		tab[index][i] = '\0';
	}
	return (tab);
}
