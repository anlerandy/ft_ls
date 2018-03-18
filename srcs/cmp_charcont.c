/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_charcont.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 02:03:06 by alerandy          #+#    #+#             */
/*   Updated: 2018/03/18 17:59:03 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			cmp_charcont(void *s1, void *s2)
{
	int		i;
	t_file	*f1;
	t_file	*f2;

	f1 = (t_file*)s1;
	f2 = (t_file*)s2;
	i = ft_strcmp(f1->name, f2->name);
	return (i);
}

int			r_cmp_charcont(void *s1, void *s2)
{
	int		i;
	t_file	*f1;
	t_file	*f2;

	f1 = (t_file*)s1;
	f2 = (t_file*)s2;
	i = ft_strcmp(f1->name, f2->name);
	return (-i);
}
