/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 02:45:16 by alerandy          #+#    #+#             */
/*   Updated: 2018/03/16 15:13:47 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		big_r(t_list **list, t_flag *flag, char *path)
{
	t_list	**tmp;
	DIR		*dir;
	char	*subpath;
	char	*str;

	tmp = list;
	subpath = ft_strdup(path);
	path = ft_strjoin(subpath, "/");
	ft_strdel(&subpath);
	while (*tmp)
	{
		if (((str = (*tmp)->content)[0] != '.' && ft_strlen(str) != 1) \
			|| ((ft_strlen(str) != 2 && str[0] != '.' && str[1] != '.')))
		{
			subpath = ft_strjoin(path, str);
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
}
