/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_data.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 23:55:26 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/16 01:15:09 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_DATA_H
# define FDF_DATA_H

// Defines
# ifndef FDF_WIN_X
#  define FDF_WIN_X 900
# endif

# ifndef FDF_WIN_Y
#  define FDF_WIN_Y 350
# endif

// Enums
# if ISLINUX > 0
enum	e_key
{
	K_ESC = 65307,
	K_RGH_ARR = 65363,
	K_UP_ARR = 65362,
	K_LFT_ARR = 65361,
	K_DWN_ARR = 65364,
	K_J = 106,
	K_K = 107,
	K_L = 108,
	K_I = 105,
};
# else
enum	e_key
{
	K_ESC = 53,
	K_RGH_ARR = 54,
	K_UP_ARR = 55,
	K_LFT_ARR = 56,
	K_DWN_ARR = 57,
};
# endif

// Structs
typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
}			t_mlx;

typedef struct s_set
{
	int				ws_x;
	int				ws_y;
	int				offset;
	int				scale_z;
	int				angle;
	int				rot;
	int				mv_x;
	int				mv_y;
	unsigned int	std_clr;
}					t_set;

typedef struct s_img
{
	char	*head;
	int		is_x;
	int		is_y;
	int		ip_x;
	int		ip_y;
	int		bpp;
	int		llen;
	int		endn;
}			t_img;

typedef struct s_pnt
{
	int				hgh;
	int				idx;
	int				idy;
	int				p_x;
	int				p_y;
	unsigned int	clr;
	struct s_pnt	*next;
}					t_pnt;

typedef struct s_fdf
{
	t_mlx	mlx;
	t_set	set;
	t_img	img;
	t_pnt	*map;
}			t_fdf;

#endif
