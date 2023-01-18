/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_putline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 23:34:07 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/18 17:01:22 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_bresenham_high(t_fdf *fdf, t_pnt *bgn, t_pnt *end, int xi);

static void	fdf_bresenham_low(t_fdf *fdf, t_pnt *bgn, t_pnt *end, int yi);

void	fdf_putline(t_fdf *fdf, t_pnt *bgn, t_pnt *end)
{
	int	dx;
	int	dy;

	dx = abs(end->p_x - bgn->p_x);
	dy = abs(end->p_y - bgn->p_y);
	if (dy < dx)
	{
		if (bgn->p_x > end->p_x)
			fdf_bresenham_low(fdf, end, bgn, 0);
		else
			fdf_bresenham_low(fdf, bgn, end, 0);
	}
	else
	{
		if (bgn->p_y > end->p_y)
			fdf_bresenham_high(fdf, end, bgn, 0);
		else
			fdf_bresenham_high(fdf, bgn, end, 0);
	}
}

static void	fdf_bresenham_low(t_fdf *fdf, t_pnt *bgn, t_pnt *end, int yi)
{
	int	dx;
	int	dy;
	int	slope;
	int	x;
	int	y;

	dx = (end->p_x - bgn->p_x);
	dy = (end->p_y - bgn->p_y);
	if ((dy < 0 && --yi) || yi++)
		dy = -dy;
	slope = (2 * dy) - dx;
	y = bgn->p_y;
	x = (bgn->p_x - 1);
	while (++x != end->p_x)
	{
		fdf_putpxl(fdf->img, x, y, 0xFFFFFF);
		if (slope > 0)
		{
			y = y + yi;
			slope = slope + (2 * (dy - dx));
		}
		else
			slope = slope + 2 * dy;
	}
	fdf_putpxl(fdf->img, x, y, 0xFFFFFF);
}

static void	fdf_bresenham_high(t_fdf *fdf, t_pnt *bgn, t_pnt *end, int xi)
{
	int	dx;
	int	dy;
	int	slope;
	int	x;
	int	y;

	dx = (end->p_x - bgn->p_x);
	dy = (end->p_y - bgn->p_y);
	if ((dx < 0 && --xi) || xi++)
		dx = -dx;
	slope = (2 * dx) - dy;
	x = bgn->p_x;
	y = (bgn->p_y - 1);
	while (++y != end->p_y)
	{
		fdf_putpxl(fdf->img, x, y, 0xFFFFFF);
		if (slope > 0)
		{
			x = x + xi;
			slope = slope + (2 * (dx - dy));
		}
		else
			slope = slope + 2 * dx;
	}
	fdf_putpxl(fdf->img, x, y, 0xFFFFFF);
}
