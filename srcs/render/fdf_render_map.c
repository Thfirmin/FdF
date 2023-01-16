/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_render_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 22:54:31 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/16 16:20:48 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_hvnext(t_pnt *map, t_pnt **nx, t_pnt **ny);

static void	fdf_plot_points(t_fdf *fdf, t_pnt *map);

static void	fdf_control_guide(t_fdf *fdf);

int	fdf_render_map(t_fdf *fdf)
{
	t_mlx	*mlx;
	t_img	img;


	mlx = &fdf->mlx;
	img = fdf->img;
	fdf_control_guide(fdf);
	fdf_tritobi(fdf, fdf->set.angle, fdf->set.rot);
	fdf_plot_points(fdf, fdf->map);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, img.ip_x, img.ip_y);
	return (0);
}

static void	fdf_control_guide(t_fdf *fdf)
{
	t_mlx	mlx;

	mlx = fdf->mlx;
	mlx_string_put(mlx.mlx, mlx.win, 5, 20, 0, "W: Move Up");
	mlx_string_put(mlx.mlx, mlx.win, 5, 35, 0, "A: Move Left");
	mlx_string_put(mlx.mlx, mlx.win, 5, 50, 0, "S: Move Down");
	mlx_string_put(mlx.mlx, mlx.win, 5, 65, 0, "D: Move Right");
	mlx_string_put(mlx.mlx, mlx.win, 5, 95, 0, "Q: Zoom In");
	mlx_string_put(mlx.mlx, mlx.win, 5, 110, 0, "E: Zoom Out");
	mlx_string_put(mlx.mlx, mlx.win, 5, 140, 0, "I: Translation Up");
	mlx_string_put(mlx.mlx, mlx.win, 5, 155, 0, "K: Translation Down");
	mlx_string_put(mlx.mlx, mlx.win, 5, 175, 0, "J: Rotate Left");
	mlx_string_put(mlx.mlx, mlx.win, 5, 190, 0, "L: Rotate Right");
	mlx_string_put(mlx.mlx, mlx.win, 5, 220, 0, "U: Plus Z-Scale");
	mlx_string_put(mlx.mlx, mlx.win, 5, 235, 0, "O: Minus Z-Scale");
}

static void	fdf_plot_points(t_fdf *fdf, t_pnt *map)
{
	t_pnt	*nxtx;
	t_pnt	*nxty;

	while (map)
	{
		fdf_hvnext(map, &nxtx, &nxty);
		if (nxtx)
			fdf_putline(fdf, map, nxtx);
		if (nxty)
			fdf_putline(fdf, map, nxty);
		map = map->next;
	}
}

static void	fdf_hvnext(t_pnt *map, t_pnt **nx, t_pnt **ny)
{
	int	x;
	int	y;

	x = map->idx;
	y = map->idy;
	*nx = 0;
	*ny = 0;
	while (map)
	{
		if (((map->idx - 1) == x) && (map->idy == y))
			*nx = map;
		if (((map->idy - 1) == y) && (map->idx == x))
			*ny = map;
		map = map->next;
	}
}
