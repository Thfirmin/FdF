/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 22:04:22 by thfirmin          #+#    #+#             */
/*   Updated: 2022/10/17 23:37:51 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <errno.h>
# include <stdio.h>

//Structs
typedef struct		s_point
{
	int				pt_x;
	int				pt_y;
	int				pt_z;
	int				pt_clr;
	struct s_point	*pt_next;
}					t_point;

typedef struct	s_graph
{
	int		win_x;
	int		win_y;
	void	*mlx;
	void	*win;
}			t_graph;

typedef struct	s_config
{
	struct s_point	*c_pnts;
	struct s_graph	*c_grph;
}					t_config;

// Error Handler
void	fdf_perror(char *error, int fd_errno);

// Config Utils
t_config	*fdf_cnfgnew(t_point *point, t_graph *graph);
void		fdf_cnfgclear(t_config *config);

// Points Utils
t_point		*fdf_pntsnew(int x, int y, int z, int clr);
void		fdf_pntsclear(t_point **point);
void		fdf_pntsadd_back(t_point **pnt, t_point *newpnt);
t_point		*fdf_pntslast(t_point *pnt);
int			fdf_pntssize(t_point *pnt);

// Graph Utils
t_graph		*fdf_grphnew(int x, int y, void *mlx, void *win);
void		fdf_grphclear(t_graph *graph);
#endif
