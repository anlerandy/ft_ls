/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 13:34:24 by alerandy          #+#    #+#             */
/*   Updated: 2018/03/21 15:26:32 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		put_lcharcont(void *cont)
{
	t_file	*file;
	char	*str;
	char	link[1024];

	ft_bzero(&link, 1024);
	file = (t_file*)cont;
	ft_putnbr(file->stat->st_nlink);
	ft_putchar(' ');
	file->user = getpwuid(file->stat->st_uid);
	ft_putstr(file->user->pw_name);
	ft_putchar(' ');
	file->group = getgrgid(file->stat->st_gid);
	ft_putstr(file->group->gr_name);
	ft_putchar(' ');
	ft_putnbr(file->stat->st_size);
	ft_putchar(' ');
	str = ctime(&(file->stat->st_mtimespec.tv_sec));
	str[ft_strlen(str) - 9] = '\0';
	ft_putstr(str + 4);
	ft_putchar(' ');
	ft_putstr(file->name);
	readlink(file->path, link, 1024) != -1 ? ft_putstr(" -> ") : 0;
	ft_putstr(link);
	ft_putendl("");
}

void		put_charcont(void *cont)
{
	t_file	*file;

	file = (t_file*)cont;
	ft_putstr(file->name);
	ft_putendl("");
}

char		*join_path(char *name, char *path)
{
	char	*str;
	char	*tmp;

	tmp = ft_strjoin(path, "/");
	str = ft_strjoin(tmp, name);
	ft_strdel(&tmp);
	return (str);
}

void		del_filecont(void *cont, size_t size)
{
	t_file	*file;

	file = (t_file*)cont;
	file->name ? ft_strdel(&(file->name)) : 0;
	file->path ? ft_strdel(&(file->path)) : 0;
	file->stat ? free(file->stat) : 0;
	file->stat = NULL;
	free(file);
	size--;
}
