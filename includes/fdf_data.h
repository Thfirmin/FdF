/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_data.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:12:57 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/06 00:33:53 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_DATA_H
# define FDF_DATA_H

// Graphic setting structure
typedef struct s_set
{
	int		std_clr;
	int		p_spc;
	int		border;
	char	*head;
	int		s_x;
	int		s_y;
	int		bpp;
	int		llen;
	int		endn;
}			t_set;

// Mlx lib structure
typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
}			t_mlx;

// Mapping points of fdf file
typedef struct s_pnt
{
	int				hgh;
	int				p_x;
	int				p_y;
	unsigned int	clr;
	struct s_pnt	*next;
}					t_pnt;

typedef struct s_point
{
	int	x;
	int	y;
	int	clr;
}		t_point;

// Fdf head structure
typedef struct s_fdf
{
	t_set	set;
	t_mlx	mlx;
	t_pnt	*map;
}			t_fdf;

// enums
# if ISLINUX > 0
enum	e_key
{
	E_ESC = 65307,
	E_H = 104,
	E_L = 108,
};
# else
enum	e_key
{
	E_ESC = 53,
	E_L = 37,
	E_H = 4,
};
# endif

void	fdf_fdfclear(t_fdf *fdf);

// Points struct
t_pnt	*fdf_pntnew(int hgh, int x, int y, unsigned int clr);
void	fdf_pntadd_back(t_pnt **map, t_pnt *point);
void	fdf_pntclear(t_pnt **pnt);
t_pnt	*fdf_pntlast(t_pnt *map);

#endif
