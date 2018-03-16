/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 15:38:35 by alerandy          #+#    #+#             */
/*   Updated: 2018/03/14 23:47:21 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstsort(t_list **alst, int (*cmp)(void *, void *))
{
	t_list		**tmp;
	t_list		*ptr;
	t_list		**ntmp;

	tmp = alst;
	while (*tmp)
	{
		ntmp = &((*tmp)->next);
		if (*ntmp && cmp((*tmp)->content, (*ntmp)->content) > 0)
		{
			ptr = *tmp;
			*tmp = *ntmp;
			*ntmp = ptr;
			ptr = (*ntmp)->next;
			(*ntmp)->next = (*tmp)->next;
			(*tmp)->next = ptr;
			tmp = alst;
		}
		else
		{
			tmp = &((*tmp)->next);
		}
	}
}
