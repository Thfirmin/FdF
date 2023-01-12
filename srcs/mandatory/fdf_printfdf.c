/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_printfdf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 01:16:56 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/11 22:48:53 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//static void	draw_circunference(t_fdf *fdf, int x, int y, long double angle);

int	fdf_printfdf(t_fdf *fdf)
{
	t_pnt	*map;
//	fdf_trdtoiso(fdf->map, 60, 330);
	map = fdf->map;
	while (map)
	{
		fdf_putpxl(fdf->set, map->p_x, map->p_y, map->clr);
		map = map->next;
	}
	mlx_put_image_to_window(fdf->mlx.mlx, fdf->mlx.win, fdf->mlx.img, 0, 0);
	return (0);
}

/*static void	draw_circunference(t_fdf *fdf, int x, int y, long double angle)
{
	long double	pi;
	int	x2;
	int	y2;

	pi = (22.0 / 7.0);
	angle = ((angle * pi) / 180);
	x2 = (int)((double)cos(angle) * fdf->set.p_spc);
	y2 = (int)((double)sin(angle) * fdf->set.p_spc);

	fdf_putpxl(fdf->set, (x + x2), (y + y2), 0x000000FF);
	fdf_putpxl(fdf->set, (x + x2), (y - y2), 0x000000FF);
	fdf_putpxl(fdf->set, (x - x2), (y + y2), 0x000000FF);
	fdf_putpxl(fdf->set, (x - x2), (y - y2), 0x000000FF);
}*/
