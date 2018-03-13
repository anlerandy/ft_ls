/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 12:08:56 by alerandy          #+#    #+#             */
/*   Updated: 2018/03/13 13:18:03 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		parse_flag(char *dive, t_flag *flag)
{
	int		i;

	i = 1;
	while (dive[i])
	{
		ft_ownchr(dive[i], "alrRt") == 0 ? usage(401, NULL, dive[i]) : 0;
		dive[i] == 'a' ? flag->a = 1 : 0;
		dive[i] == 'l' ? flag->l = 1 : 0;
		dive[i] == 'R' ? flag->R = 1 : 0;
		dive[i] == 'r' ? flag->r = 1 : 0;
		dive[i] == 't' ? flag->t = 1 : 0;
		i++;
	}
	ft_putendl(dive);
	ft_putnbr(flag->a);
	ft_putchar('\n');
	ft_putnbr(flag->l);
	ft_putchar('\n');
	ft_putnbr(flag->R);
	ft_putchar('\n');
	ft_putnbr(flag->r);
	ft_putchar('\n');
	ft_putnbr(flag->t);
	ft_putchar('\n');
}

int			main(int ac, char **av)
{
	int		i;
	DIR		**dir;
	struct dirent *fold;
	int		fd;
	t_flag	*flag;

	fd = 0;
	i = 0;
	fold = NULL;
	dir = ft_memalloc(sizeof(DIR *) * (ac - 1));
	flag = ft_memalloc(sizeof(t_flag));
	while (++i < ac)
	{
		if (i == 1 && av[i][0] == '-' && ft_strlen(av[i]) > 1)
			parse_flag(av[i], flag);
		else
			dir[i - 1] = opendir(av[i]);
	}
	i = 0;
	while (++i < ac)
	{
		if (dir[i - 1] == NULL)
		{
			if ((fd = open(av[i], O_RDONLY)) > 0)
			{
				ft_putendl(av[i]);
				close(fd);
			}
			else if (i != 1 || (av[i][0] == '-' && ft_strlen(av[i]) == 1))
				usage(1, av[i], 0);
		}
		else
		{
			i != 1 ? ft_putchar('\n') : 0;
			ac > 2 ? ft_putstr(av[i]) : 0;
			ac > 2 ? ft_putendl(":") : 0;
			while ((fold = readdir(dir[i - 1])))
			{
				fold->d_name[0] != '.' ? ft_putendl(fold->d_name) : 0;
			}
			closedir(dir[i - 1]);
		}
	}
	return (0);
}
