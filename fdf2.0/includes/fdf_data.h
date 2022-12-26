/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_data.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:12:57 by thfirmin          #+#    #+#             */
/*   Updated: 2022/12/25 21:39:02 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_DATA_H
# define FDF_DATA_H
# include <stdio.h>
# include "libft.h"

typedef struct s_pnt
{
	int				hgh;
	int				p_x;
	int				p_y;
	int				clr;
	struct s_pnt	*next;
}					t_pnt;

// Points struct
t_pnt	*fdf_pntnew(int hgh, int x, int y, int clr);
void	fdf_pntadd_back(t_pnt **map, t_pnt *point);
void	fdf_pntclear(t_pnt **pnt);

#endif
