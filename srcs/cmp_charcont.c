/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_charcont.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 02:03:06 by alerandy          #+#    #+#             */
/*   Updated: 2018/03/15 02:03:20 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			cmp_charcont(void *s1, void *s2)
{
	int		i;

	i = ft_strcmp((char*)s1, (char*)s2);
	return (i);
}

int			r_cmp_charcont(void *s1, void *s2)
{
	int		i;

	i = ft_strcmp((char*)s1, (char*)s2);
	return (-i);
}
