/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_render_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 22:54:31 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/17 02:55:50 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_pnt	*fdf_hvnext(t_pnt *map, int x, int y, int bin);

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
	mlx_string_put(mlx.mlx, mlx.win, 5, 265, 0, "SPACE: Reset default set");
}

static void	fdf_plot_points(t_fdf *fdf, t_pnt *map)
{
	t_pnt	*nxt;

	while (map)
	{
		nxt = fdf_hvnext(fdf->map, map->idx, map->idy, 0);
		if (nxt)
			fdf_putline(fdf, map, nxt);
		nxt = fdf_hvnext(fdf->map, map->idx, map->idy, 1);
		if (nxt)
			fdf_putline(fdf, nxt, map);
		map = map->next;
	}
}

static t_pnt	*fdf_hvnext(t_pnt *map, int x, int y, int bin)
{
	while (map)
	{
		if (!bin)
		{
			if (((map->idx - 1) == x) && (map->idy == y))
				return (map);
		}
		else
		{
			if (((map->idy - 1) == y) && (map->idx == x))
				return (map);
		}
		map =  map->next;
	}
	return (0);
}

