/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_data.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 23:55:26 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/17 02:51:02 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_DATA_H
# define FDF_DATA_H

// Defines
# ifndef FDF_WIN_X
#  define FDF_WIN_X 1366
# endif

# ifndef FDF_WIN_Y
#  define FDF_WIN_Y 768
# endif

// Enums
# if ISLINUX > 0
enum	e_key
{
	K_ESC = 65307,
	K_A = 97,
	K_D = 100,
	K_E = 101,
	K_I = 105,
	K_J = 106,
	K_K = 107,
	K_L = 108,
	K_O = 111,
	K_Q = 113,
	K_S = 115,
	K_U = 117,
	K_W = 119,
	K_ESP = 32,
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
