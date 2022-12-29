/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_data.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:12:57 by thfirmin          #+#    #+#             */
/*   Updated: 2022/12/29 14:30:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_DATA_H
# define FDF_DATA_H
# include <stdio.h>
# include "libft.h"

// Standard fdf configurations
typedef struct s_config
{
	unsigned int	std_color;
	unsigned int	sz_x;
	unsigned int	sz_y;
}					t_config;

// Mapping points of fdf file
typedef struct s_pnt
{
	int				hgh;
	int				p_x;
	int				p_y;
	unsigned int	clr;
	struct s_pnt	*next;
}					t_pnt;

// Setting master  of fdf
typedef struct s_fdf
{
	t_config	*cnfg;
	t_pnt		*map;
}				t_fdf;

// Fdf head setting
void	fdf_init_setting(char *pathmap, t_fdf **fdf);
void	fdf_fdfclear(t_fdf **fdf);

// Standard config
void	fdf_std_settings(t_fdf **fdf);

// Points struct
t_pnt	*fdf_pntnew(int hgh, int x, int y, unsigned int clr);
void	fdf_pntadd_back(t_pnt **map, t_pnt *point);
void	fdf_pntclear(t_pnt **pnt);
t_pnt	*fdf_pntlast(t_pnt *map);

#endif
