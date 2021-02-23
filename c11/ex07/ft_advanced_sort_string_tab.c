/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 10:50:26 by qujacob           #+#    #+#             */
/*   Updated: 2021/02/23 12:04:36 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **s1, char **s2)
{
	char *bank;

	bank = *s1;
	*s1 = *s2;
	*s2 = bank;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int i;
	int j;
	int min;

	i = 0;
	while (tab[i + 2] != 0)
	{
		min = i;
		j = i + 1;
		while (tab[j + 1] != 0)
		{
			if (cmp(tab[min], tab[j]) > 0)
				min = j;
			if (min != i)
				ft_swap(&tab[i], &tab[min]);
			j++;
		}
		i++;
	}
}
