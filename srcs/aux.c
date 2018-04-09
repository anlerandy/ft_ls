/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 13:34:24 by alerandy          #+#    #+#             */
/*   Updated: 2018/04/09 15:37:19 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_internjoin(char **begin, char *sep, char *toadd)
{
	char	*str;
	int		i;

	i = 0;
	if (*begin)
		i = ft_strlen(*begin);
	str = ft_memalloc(sizeof(char) * (i + ft_strlen(sep) + \
				ft_strlen(toadd)) + 1);
	if (*begin)
	{
		ft_strcat(str, *begin);
		ft_strcat(str, sep);
	}
	ft_strcat(str, toadd);
	ft_strdel(begin);
	*begin = str;
}

void		put_lcharcont(void *cont)
{
	t_file	*file;
	char	*str;
	char	link[1024];
	char	*tmp;

	str = NULL;
	ft_bzero(&link, 1024);
	file = (t_file*)cont;
	str = ft_itoa(file->stat->st_nlink);
	file->user = getpwuid(file->stat->st_uid);
	ft_internjoin(&str, " ", file->user->pw_name);
	file->group = getgrgid(file->stat->st_gid);
	ft_internjoin(&str, " ", file->group->gr_name);
	ft_internjoin(&str, " ", (tmp = ft_itoa(file->stat->st_size)));
	ft_strdel(&tmp);
	tmp = ctime(&(file->stat->st_mtimespec.tv_sec));
	tmp[ft_strlen(tmp) - 9] = '\0';
	ft_internjoin(&str, " ", tmp + 4);
	ft_internjoin(&str, " ", file->name);
	readlink(file->path, link, 1024) != -1 ? ft_internjoin(&str, " ", "->") : 0;
	ft_internjoin(&str, " ", link);
	ft_putendl(str);
	ft_strdel(&str);
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
