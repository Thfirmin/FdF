/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 00:48:58 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/16 16:12:26 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_fill_img(t_mlx mlx, int color);

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

	img = &fdf->img;
	mlx = &fdf->mlx;
	img->is_x = FDF_WIN_X - ((FDF_WIN_X * 15) / 100);
	img->is_y = FDF_WIN_Y;
	img->ip_x = (0 + ((FDF_WIN_X * 15) / 100));
	img->ip_y = 0;
	printf ("win size %d x %d\n img size %d x %d\n img pos %d x %d\n", FDF_WIN_X, FDF_WIN_Y, fdf->img.is_x, fdf->img.is_y, fdf->img.ip_x, fdf->img.ip_y);
	mlx->img = mlx_new_image(mlx->mlx, img->is_x, img->is_y);
	fdf_fill_img(fdf->mlx, 0xDFDADA);
	if (!mlx->img)
		fdf_error_handler("Image create has been failed", fdf);
	img->head = mlx_get_data_addr(mlx->img, &img->bpp, &img->llen, &img->endn);
}

static void	fdf_fill_img(t_mlx mlx, int color)
{
	int y;
	int	x;

	y = -1;
	while (++y < FDF_WIN_Y)
	{
		x = -1;
		while (++x < FDF_WIN_X)
			mlx_pixel_put(mlx.mlx, mlx.win, x, y, color);
	}
}
