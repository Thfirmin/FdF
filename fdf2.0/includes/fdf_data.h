/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_data.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:12:57 by thfirmin          #+#    #+#             */
/*   Updated: 2022/12/28 00:11:54 by thfirmin         ###   ########.fr       */
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
t_fdf	*fdf_init_setting(char *pathmap);

// Standard config
void	fdf_std_settings(t_fdf *fdf);

// Points struct
t_pnt	*fdf_pntnew(int hgh, int x, int y, unsigned int clr);
void	fdf_pntadd_back(t_pnt **map, t_pnt *point);
void	fdf_pntclear(t_pnt **pnt);

#endif
