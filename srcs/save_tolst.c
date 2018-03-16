/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_tolst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 02:43:51 by alerandy          #+#    #+#             */
/*   Updated: 2018/03/16 20:25:23 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		del_charcont(void *cont, size_t size)
{
	char	*str;

	size--;
	str = (char *)cont;
	ft_memset(str, 1, size);
	ft_strdel(&str);
}

void		put_charcont(void *cont)
{
	ft_putendl(cont);
}

void		fold_tolst(DIR **dir, t_flag *flag, t_list **list)
{
	_DIRENT	*fold;
	t_list	*tmp;

	fold = NULL;
	tmp = NULL;
	while ((fold = readdir(*dir)))
		if (fold->d_name[0] != '.' || flag->a)
		{
			if (*list)
			{
				tmp = ft_lstnew(fold->d_name, ft_strlen(fold->d_name) + 1);
				ft_lstadd(list, tmp);
//				ft_lstdel(&tmp, &del_charcont);
			}
			else
				*list = ft_lstnew(fold->d_name, ft_strlen(fold->d_name) + 1);
		}
}

void		save_dir(DIR **dir, t_flag *flag, char *path)
{
	int		fd;
	int		i;
	t_list	*list;

	list = NULL;
	i = 0;
	if (*dir)
	{
		fold_tolst(dir, flag, &list);
	}
	else
		(fd = open(path, O_RDONLY)) > 0 ? ft_putendl(path) : 0;
	!flag->f && !flag->r ? ft_lstsort(&list, &cmp_charcont) : 0;
	!flag->f && flag->r ? ft_lstsort(&list, &r_cmp_charcont) : 0;
	ft_putlst(&list, &put_charcont);
	flag->upr ? big_r(list, flag, path) : 0;
	*dir ? closedir(*dir) : 0;
//	ft_lstdel(&list, &del_charcont);
}
