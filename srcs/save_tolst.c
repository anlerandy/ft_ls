/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_tolst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 02:43:51 by alerandy          #+#    #+#             */
/*   Updated: 2018/03/16 15:40:29 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		put_charcont(void *cont)
{
	ft_putendl(cont);
}

void		save_dir(DIR **dir, t_flag *flag, char *path)
{
	struct dirent	*fold;
	int				fd;
	int				i;
	t_list			*list;

	list = NULL;
	fold = NULL;
	i = 0;
	if (*dir)
	{
		while ((fold = readdir(*dir)))
			if (fold->d_name[0] != '.' || flag->a)
				list ? ft_lstadd(&list, \
				ft_lstnew(fold->d_name, ft_strlen(fold->d_name) + 1)) : \
				(list = ft_lstnew(fold->d_name, ft_strlen(fold->d_name) + 1));
	}
	else
		(fd = open(path, O_RDONLY)) > 0 ? ft_putendl(path) : 0;
	!flag->f && !flag->r ? ft_lstsort(&list, &cmp_charcont) : 0;
	!flag->f && flag->r ? ft_lstsort(&list, &r_cmp_charcont) : 0;
	ft_putlst(&list, &put_charcont);
	flag->upr ? big_r(&list, flag, path) : 0;
	*dir ? closedir(*dir) : 0;
}
