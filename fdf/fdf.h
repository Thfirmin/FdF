/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 20:38:19 by thfirmin          #+#    #+#             */
/*   Updated: 2022/09/25 06:36:30 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define KEY_ESC 53
# define CLOSE_BUTTON 17
# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_point
{
	int				pt_x;
	int				pt_y;
	int				pt_z;
	int				pt_clr;
	struct s_point	*pt_next;
}					t_point;

typedef struct s_window
{
	void			*mlx;
	void			*win;
	int				win_x;
	int				win_y;
	struct s_point	*fdf_pnt;
}					t_window;

// Utils
int		fdf_getnbr(char *nbr);
int		fdf_todec(char *nbr, int base);
void	fdf_free_split(char **split);
char	**fdf_getting_splited(int fd);
char	*fdf_take_zclr_arg(char *zclr, int base, int *start);

// Pnt Utils
t_point	*fdf_pntnew(int x, int y, int z, int clr);
t_point	*fdf_pntlast(t_point *pnt);
void	fdf_pntadd_back(t_point **pnt, t_point *new);
void	fdf_pntclear(t_point **pnt);
t_window	*fdf_winnew(void *mlx, void *win, int win_xy[2], t_point *fdf_pnt);

// Map Vaidate
t_point	*fdf_map_analysis(int fd);

// Error Handler
void	invalid_argument(void);
void	file_not_found(char *file);
void	wrong_llength(void);

//render window
int		window_length(t_point *pnt, int axis);
int		close_window(t_window *fdf);
int		window_key(int keycode, t_window *fdf);
int		draw_window(t_window *fdf);
#endif
