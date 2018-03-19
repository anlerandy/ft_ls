/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 11:39:08 by alerandy          #+#    #+#             */
/*   Updated: 2018/03/19 19:56:13 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		usage(int e, char *name, char c)
{
	ft_putstr("ft_ls: ");
	name ? ft_putstr(name) : 0;
	name ? ft_putstr(": ") : 0;
	e == 1 ? ft_putstr("No such file or directory.") : 0;
	e == 2 ? ft_putstr("stat failed whith : ") : 0;
	e == 2 && name ? ft_putstr(name) : 0;
	e == 400 ? ft_putstr("Memory allocation fatal error.") : 0;
	e == 401 ? ft_putstr("illegal option -- ") : 0;
	e == 401 && c != 0 ? ft_putchar(c) : 0;
	e == 401 && c != 0 ? ft_putstr("\nusage: ls [Raflrt] [file ...]") : 0;
	ft_putendl("");
	e >= 400 ? perror("") : 0;
	e >= 400 ? exit(0) : 0;
}
