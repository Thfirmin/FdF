/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:13:11 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/06 05:27:21 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_print_bresenham(t_fdf *fdf, t_point bgn, t_point end);

static void	fdf_print_straight(t_fdf *fdf, t_point bgn, t_point end);

void	fdf_putpxl(t_set set, int x, int y, int color)
{
	char	*begin;

	begin = set.head + (y * set.llen + x * (set.bpp / 8));
	*(unsigned int *)begin = color;
}

void	fdf_putline(t_fdf *fdf, t_point *bgn, t_point *end)
{
	fdf_putpxl(fdf->set, bgn->x, bgn->y, 0x00FFFFFF);
	if ((bgn->x == end->x) || (bgn->y == end->y))
		fdf_print_straight(fdf, *bgn, *end);
	else
		fdf_print_bresenham(fdf, *bgn, *end);
}

static void	fdf_print_straight(t_fdf *fdf, t_point bgn, t_point end)
{
	while ((bgn.x != end.x) || (bgn.y != end.y))
	{
		if (bgn.x < end.x)
			bgn.x ++;
		else
			bgn.x --;
		if (bgn.y < end.y)
			bgn.y ++;
		else
			bgn.y --;
		fdf_putpxl(fdf->set, bgn.x, bgn.y, 0x00FFFFFF);
	}
}

static void	fdf_print_bresenham(t_fdf *fdf, t_point bgn, t_point end)
{
	int	di;

	di = ((2 * abs(end.y - bgn.y)) - abs(end.x - bgn.x));

	while ((bgn.x != end.x) || (bgn.y != end.y))
	if (!di)
		di ++;
	if (di > 0)
	{
		bgn.x += ((end.x - bgn.x) / abs(end.x - bgn.x));
		bgn.y += ((end.y - bgn.y) / abs(end.y - bgn.y));
		di += ((2 * abs(end.y - bgn.y)) - (2 * abs(end.x - bgn.x)));
	}
	else if (di < 0)
	{
		bgn.x += ((end.x - bgn.x) / abs(end.x - bgn.x));
		di += (2 * abs(end.y - bgn.y));
	}
	fdf_putpxl(fdf->set, bgn.x, bgn.y, 0x00FFFFFF);
}
