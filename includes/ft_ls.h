/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 12:09:23 by alerandy          #+#    #+#             */
/*   Updated: 2018/03/13 13:17:42 by alerandy         ###   ########.fr       */
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
	int			R;
	int			a;
	int			r;
	int			t;
}				t_flag;

void			usage(int e, char *name, char c);

#endif
