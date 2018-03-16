/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 02:42:31 by alerandy          #+#    #+#             */
/*   Updated: 2018/03/15 04:20:17 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putlst(t_list **list, void (*put) (void *cont))
{
	t_list	**tmp;

	tmp = list;
	while (*tmp)
	{
		put((*tmp)->content);
		tmp = &(*tmp)->next;
	}
}
