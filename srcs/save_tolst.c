/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_tolst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 02:43:51 by alerandy          #+#    #+#             */
/*   Updated: 2018/03/18 19:02:17 by alerandy         ###   ########.fr       */
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
	t_file	*file;

	file = (t_file*)cont;
	file->user = getpwuid(file->stat->st_uid);
	ft_putstr(file->user->pw_name);
	ft_putchar(' ');
	ft_putstr(file->name);
	ft_putchar(' ');
	ft_putstr(ctime(&(file->stat->st_mtimespec.tv_sec)));
}

char		*join_path(char *name, char *path)
{
	char	*str;
	char	*tmp;

	tmp = ft_strjoin(path, "/");
	str = ft_strjoin(tmp, name);
	free(tmp);
	return (str);
}

void		fold_tolst(DIR **dir, t_flag *flag, t_list **list, char *path)
{
	_DIRENT	*fold;
	t_list	*tmp;
	t_file	file;

	fold = NULL;
	tmp = NULL;
	while ((fold = readdir(*dir)))
		if (fold->d_name[0] != '.' || flag->a)
		{
			file.name = ft_strdup(fold->d_name);
			file.path = join_path(file.name, path);
			file.stat = ft_memalloc(sizeof(_STAT));
			if (flag->l && (flag->serr = stat(file.path, file.stat) == -1))
				usage(2, file.path, 0);
			if (*list)
			{
				tmp = ft_lstnew(&file, sizeof(t_file));
				ft_lstadd(list, tmp);
//				ft_lstdel(&tmp, &del_charcont);
			}
			else
				*list = ft_lstnew(&file, sizeof(t_file));
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
		fold_tolst(dir, flag, &list, path);
	else
		(fd = open(path, O_RDONLY)) > 0 ? ft_putendl(path) : 0;
	!flag->f && !flag->r ? ft_lstsort(&list, &cmp_charcont) : 0;
	!flag->f && flag->r ? ft_lstsort(&list, &r_cmp_charcont) : 0;
	ft_putlst(&list, &put_charcont);
	flag->upr ? big_r(list, flag, path) : 0;
	*dir ? closedir(*dir) : 0;
//	ft_lstdel(&list, &del_charcont);
}
