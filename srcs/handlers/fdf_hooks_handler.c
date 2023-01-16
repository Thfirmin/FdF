/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 22:37:23 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/16 01:33:24 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int fdf_cross(t_fdf *fdf);

static int	fdf_keyhandler(int key, t_fdf *fdf);

void	fdf_hooks_handler(t_fdf *fdf)
{
	mlx_hook(fdf->mlx.win, 2, 1L<<0, fdf_keyhandler, fdf);
	mlx_hook(fdf->mlx.win, 17, 0, fdf_cross, fdf);
}

static int	fdf_keyhandler(int key, t_fdf *fdf)
{
	if (key == K_ESC)
		fdf_cross(fdf);
	else if ((key == K_UP_ARR) || (key == K_DWN_ARR))
		fdf_move_map(fdf, key);
	else if ((key == K_RGH_ARR) || (key == K_LFT_ARR))
		fdf_move_map(fdf, key);
	else if ((key == K_I) || (key == K_K))
		fdf_rot_map(fdf, key);
	else if ((key == K_J) || (key == K_L))
		fdf_rot_map(fdf, key);
	else if ((key == K_PLUS) || (key == K_MINUS))
		fdf_resize_map(fdf, key);
	else if ((key == K_U) || (key == K_O))
		fdf_resize_map(fdf, key);
	else
		printf ("key = %d\n", key);
	ft_bzero(fdf->img.head, (fdf->img.is_y * fdf->img.llen));
	return (0);
}

static int	fdf_cross(t_fdf *fdf)
{
	fdf_head_handler(fdf);
	exit(0);
}
