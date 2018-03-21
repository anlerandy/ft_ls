/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 02:45:16 by alerandy          #+#    #+#             */
/*   Updated: 2018/03/21 19:07:10 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		big_r(t_list *list, t_flag *flag, char *path)
{
	t_list	**tmp;
	DIR		*dir;
	char	*subpath;
	t_file	*file;

	tmp = &list;
	path = ft_strjoin(path, "/");
	while (*tmp)
	{
		if (((file = (*tmp)->content)->name[0] != '.' &&  \
				ft_strlen(file->name) != 1) || ((ft_strlen(file->name) != 2 \
						&& file->name[0] != '.' && file->name[1] != '.')))
		{
			subpath = ft_strjoin(path, file->name);
			if ((dir = opendir(subpath)))
			{
				ft_putendl("");
				ft_putendl(subpath);
				save_dir(&dir, flag, subpath);
			}
			ft_strdel(&subpath);
		}
		tmp = &(*tmp)->next;
	}
	ft_strdel(&path);
}
