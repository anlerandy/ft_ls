/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 12:09:23 by alerandy          #+#    #+#             */
/*   Updated: 2018/03/16 15:12:38 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/includes/libft.h"

# include <dirent.h>
# include <sys/types.h>
# include <sys/dir.h>

typedef struct	s_flag
{
	int			l;
	int			upr;
	int			a;
	int			r;
	int			t;
	int			f;
}				t_flag;

void			usage(int e, char *name, char c);
int				cmp_charcont(void *s1, void *s2);
int				r_cmp_charcont(void *s1, void *s2);
void			save_dir(DIR **dir, t_flag *flag, char *path);
void			big_r(t_list **list, t_flag *flag, char *path);

#endif
