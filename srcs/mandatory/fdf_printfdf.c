/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_printfdf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 01:16:56 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/10 03:25:03 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//static void	draw_circunference(t_fdf *fdf, int x, int y, long double angle);

static void	fdf_putguideline(t_fdf *fdf);

int	fdf_printfdf(t_fdf *fdf)
{
	int	c_x = fdf->set.s_x / 2;
	int c_y = fdf->set.s_y / 2;
	t_point bgn = {c_x, c_y, 0x00FF0000};
	t_point end = {c_x + 90, c_y + 25, 0x000000FF};

	fdf_putguideline(fdf);
	fdf_putline(fdf, &bgn, &end);
	/*int	c_x = fdf->set.s_x / 2;
	int	c_y = fdf->set.s_y / 2;

	t_point	begin = { c_x, c_y, 0x00FFFFFF };
	t_point end = { (c_x + 23), c_y, 0x00FFFFFF };
	draw_margins(fdf);
	for (int i = 0; i < fdf->set.s_x - 1; i ++)
		fdf_putpxl(fdf->set, i, fdf->set.s_y / 2, 0x00FFFFFF);
	for (int i = 0; i < fdf->set.s_y - 1; i ++)
		fdf_putpxl(fdf->set, fdf->set.s_x / 2, i, 0x00FFFFFF);
	draw_circunference(fdf, (fdf->set.s_x / 2), (fdf->set.s_y / 2), 30);
	mlx_put_image_to_window(fdf->mlx.mlx, fdf->mlx.win, fdf->mlx.img, 0, 0);
	fdf_putline(fdf, &begin, &end);
	//fdf_putline(fdf, c_x, c_y, (c_x + 15), (c_y - 7));
	//fdf_putline(fdf, c_x, c_y, (c_x - 15), (c_y + 7));
	//fdf_putline(fdf, c_x, c_y, (c_x - 15), (c_y - 7));
	mlx_put_image_to_window(fdf->mlx.mlx, fdf->mlx.win, fdf->mlx.img, 0, 0);*/
	mlx_put_image_to_window(fdf->mlx.mlx, fdf->mlx.win, fdf->mlx.img, 0, 0);
	return (0);
}

static void	fdf_putguideline(t_fdf *fdf)
{
	(void) fdf;
	for (int i = 0; i < fdf->set.s_x; i ++)
		fdf_putpxl(fdf->set, i, (fdf->set.s_y / 2), 0x00FFFFFF);
	for (int i = 0; i < fdf->set.s_y; i ++)
		fdf_putpxl(fdf->set, (fdf->set.s_x / 2), i, 0x00FFFFFF);
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
