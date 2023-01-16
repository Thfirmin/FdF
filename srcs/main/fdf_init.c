/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 00:48:58 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/15 22:59:55 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_init_image(t_fdf *fdf);

static void	fdf_init_window(t_fdf *fdf);

void	fdf_init(t_fdf *fdf, char *pathmap)
{
	fdf->mlx.mlx = mlx_init();
	if (!fdf->mlx.mlx)
		fdf_error_handler("mlx instance creat has been failed", 0);
	fdf_init_window(fdf);
	fdf_init_map(fdf, pathmap);
	fdf_init_image(fdf);
}

static void	fdf_init_window(t_fdf *fdf)
{
	t_set	*set;

	set = &fdf->set;
	set->ws_x = FDF_WIN_X;
	set->ws_y = FDF_WIN_Y;
	fdf->mlx.win = mlx_new_window(fdf->mlx.mlx, set->ws_x, set->ws_y, "FDF");
	if (!fdf->mlx.win)
		fdf_error_handler("Window create has been failed", fdf);
}

static void	fdf_init_image(t_fdf *fdf)
{
	//t_pnt	*lst;
	t_img	*img;
	t_mlx	*mlx;

	//lst = fdf_pntlast(fdf->map);
	img = &fdf->img;
	mlx = &fdf->mlx;
	//img->is_x = abs(lst->idx * fdf->set.offset);
	//img->is_y = abs(lst->idy * fdf->set.offset);
	img->is_x = FDF_WIN_X;
	img->is_y = FDF_WIN_Y;
	img->ip_x = ((fdf->set.ws_x / 2) - (img->is_x / 2));
	img->ip_y = ((fdf->set.ws_y / 2) - (img->is_y / 2));
	mlx->img = mlx_new_image(mlx->mlx, img->is_x, img->is_y);
	if (!mlx->img)
		fdf_error_handler("Image create has been failed", fdf);
	img->head = mlx_get_data_addr(mlx->img, &img->bpp, &img->llen, &img->endn);
}
