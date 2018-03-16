/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 12:08:56 by alerandy          #+#    #+#             */
/*   Updated: 2018/03/16 19:52:17 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		sort_char_table(char **tab, int len, int way)
{
	char	*tmp;
	int		i;

	i = 0;
	while (i < len && i + 1 < len)
	{
		if (!way ? ft_strcmp(tab[i], tab[i + 1]) > 0 : \
				ft_strcmp(tab[i], tab[i + 1]) < 0)
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
}

void		parse_flag(char *dive, t_flag *flag)
{
	int		i;

	i = 1;
	while (dive[i])
	{
		ft_ownchr(dive[i], "alrRtf") == 0 ? usage(401, NULL, dive[i]) : 0;
		dive[i] == 'a' || dive[i] == 'f' ? flag->a = 1 : 0;
		dive[i] == 'l' ? flag->l = 1 : 0;
		dive[i] == 'R' ? flag->upr = 1 : 0;
		dive[i] == 'r' ? flag->r = 1 : 0;
		dive[i] == 't' ? flag->t = 1 : 0;
		dive[i] == 'f' ? flag->f = 1 : 0;
		i++;
	}
}

int			dir_opener(int i, int ac, char **av, DIR **dir)
{
	int		cur;
	int		fd;

	cur = i--;
	while (++i - cur < ac - cur)
	{
		dir[i - cur] = opendir(av[i]);
		if (!dir[i - cur])
			(fd = open(av[i], O_RDONLY)) <= 0 ? usage(1, av[i], 0) : 0;
		fd > 0 ? close(fd) : 0;
	}
	return (cur);
}

void		first_occurence(int ac, DIR **dir, char **av, t_flag *flag)
{
	int		i;
	DIR		*dot;

	i = -1;
	if (++i == ac)
	{
		dot = opendir(".");
		save_dir(&dot, flag, ".");
	}
	else
	{
		i = -1;
		while (++i < ac)
		{
			dir[i] && ac > 1 ? ft_putstr(av[i]) : 0;
			dir[i] && ac > 1 ? ft_putendl(":") : 0;
			save_dir(&(dir[i]), flag, av[i]);
			i != ac - 1 ? ft_putchar('\n') : 0;
		}
	}
}

int			main(int ac, char **av)
{
	int		i;
	t_flag	*flag;
	DIR		**dir;
	int		cur;

	i = 1;
	flag = NULL;
	!(flag = ft_memalloc(sizeof(t_flag))) ? usage(400, NULL, 0) : 0;
	while (i < ac && av[i][0] == '-' && ft_strlen(av[i]) > 1)
		parse_flag(av[i++], flag);
	dir = ft_memalloc(sizeof(DIR *) * (ac - i));
	sort_char_table(av + i, ac - i, flag->r);
	cur = dir_opener(i, ac, av, dir);
	first_occurence(ac - cur, dir, av + cur, flag);
	return (0);
}
