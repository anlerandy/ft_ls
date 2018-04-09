/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_tolst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 02:43:51 by alerandy          #+#    #+#             */
/*   Updated: 2018/04/09 09:57:46 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_lstpushback(t_list **list, t_file file)
{
	t_list	**nlist;

	nlist = list;
	if (*list)
	{
		while (*nlist && (*nlist)->next)
			nlist = &((*nlist)->next);
		(*nlist)->next = ft_lstnew(&file, sizeof(t_file));
	}
	else
		*list = ft_lstnew(&file, sizeof(t_file));
}

void		fold_tolst(DIR **dir, t_flag *flag, t_list **list, char *path)
{
	_DIRENT	*fold;
	t_list	*tmp;
	t_file	file;

	fold = NULL;
	tmp = NULL;
	file.path = NULL;
	file.name = NULL;
	while ((fold = readdir(*dir)))
		if (fold->d_name[0] != '.' || flag->a)
		{
			file.name = ft_strdup(fold->d_name);
			file.path = join_path(file.name, path);
			file.stat = ft_memalloc(sizeof(_STAT));
			if (flag->l && (flag->serr = lstat(file.path, file.stat) == -1))
				usage(402, file.path, 0);
			ft_lstpushback(list, file);
		}
}

void		ft_lstat(char *path)
{
	_STAT	*stat;
	int		err;

	stat = ft_memalloc(sizeof(_STAT));
	err = lstat(path, stat);
	if (err < 0)
		usage(3, path, 0);
	free(stat);
}

void		save_dir(DIR **dir, t_flag *flag, char *path)
{
	int		i;
	t_list	*list;

	list = NULL;
	i = 0;
	if (*dir)
		fold_tolst(dir, flag, &list, path);
	!flag->f && !flag->r ? ft_lstsort(&list, &cmp_charcont) : 0;
	!flag->f && flag->r ? ft_lstsort(&list, &r_cmp_charcont) : 0;
	flag->l ? ft_putlst(&list, &put_lcharcont) : \
		ft_putlst(&list, &put_charcont);
	flag->upr ? big_r(list, flag, path) : 0;
	ft_lstdel(&list, &del_filecont);
	*dir ? closedir(*dir) : 0;
}
