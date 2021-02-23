/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 11:09:07 by qujacob           #+#    #+#             */
/*   Updated: 2021/02/18 09:42:33 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	dest = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

int		final_size(int size, char **strs, char *sep)
{
	int index;
	int total_size;

	total_size = 0;
	index = -1;
	while (++index < size)
	{
		total_size += ft_strlen(strs[index]);
		if (index < size - 1)
			total_size += ft_strlen(sep);
	}
	return (total_size);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*final_str;
	int		total_size;
	int		index;

	if (size <= 0)
	{
		final_str = (char *)malloc(sizeof(char));
		final_str[0] = '\0';
		return (final_str);
	}
	total_size = final_size(size, strs, sep);
	if (!(final_str = (char *)malloc(sizeof(char) * (total_size + 1))))
		return (NULL);
	index = -1;
	final_str[0] = '\0';
	while (++index < size)
	{
		final_str = ft_strcat(final_str, strs[index]);
		if (index < size - 1)
			final_str = ft_strcat(final_str, sep);
	}
	final_str[total_size] = '\0';
	return (final_str);
}
