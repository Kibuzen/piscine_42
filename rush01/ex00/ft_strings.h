/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 09:04:11 by qujacob           #+#    #+#             */
/*   Updated: 2021/02/14 15:46:42 by mtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRINGS_H
# define FT_STRINGS_H

# include <unistd.h>
# include <stdlib.h>

int		ft_strlen(char *str);
void	ft_putstr(char *str);
int		count_words(char *str);
int		*ft_parse(char *av);
void	ft_putnbr(int nb);

#endif
