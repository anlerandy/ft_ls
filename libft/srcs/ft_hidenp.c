/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hidenp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:27:52 by alerandy          #+#    #+#             */
/*   Updated: 2018/03/13 13:13:17 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_ownchr(const char c, const char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
		if (s2[i++] == c)
			return (1);
	return (0);
}

int		ft_hidenp(const char *s1, const char *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1[i])
		return (1);
	while (s1[i] && s2[j])
	{
		if (s1[i] == s2[j])
			i++;
		j++;
		if (!s1[i])
			return (1);
	}
	return (0);
}
