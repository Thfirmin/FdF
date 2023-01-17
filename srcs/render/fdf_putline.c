/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_putline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 23:34:07 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/17 16:03:02 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_bresenhamx(t_fdf *fdf, t_pnt *bgn, t_pnt *end, int bin);

static void	fdf_bresenhamy(t_fdf *fdf, t_pnt *bgn, t_pnt *end, int bin);

void	fdf_putline(t_fdf *fdf, t_pnt *bgn, t_pnt *end)
{
	int	bin;
	int	dx;
	int	dy;

	dx = abs(end->p_x - bgn->p_x);
	dy = abs(end->p_y - bgn->p_y);
	bin = !(dx > dy);
	if (!bin)
		fdf_bresenhamx(fdf, bgn, end, bin);
	else
		fdf_bresenhamy(fdf, bgn, end, bin);
}

static void	fdf_bresenhamx(t_fdf *fdf, t_pnt *bgn, t_pnt *end, int bin)
{
	int	slope;
	int	x;
	int	y;

	slope = ((2 * abs(end->p_y - bgn->p_y)) - abs(end->p_x - bgn->p_x));
	x = bgn->p_x;
	y = bgn->p_y;
	fdf_putpxl(fdf->img, x, y, fdf_clr(bgn, end, x, bin));
	while (x != end->p_x)
	{
		if (x < end->p_x)
			x ++;
		else if (x > end->p_x)
			x --;
		slope += (2 * abs(end->p_y - bgn->p_y));
		if (slope >= 0)
		{
			if (y < end->p_y)
				y ++;
			else if (y > end->p_y)
				y --;
			slope -= (2 * abs(end->p_x - bgn->p_x));
		}
		fdf_putpxl(fdf->img, x, y, fdf_clr(bgn, end, x, bin));
	}	
}

static void	fdf_bresenhamy(t_fdf *fdf, t_pnt *bgn, t_pnt *end, int bin)
{
	int	slope;
	int	x;
	int	y;

	slope = ((2 * abs(end->p_y - bgn->p_y)) - abs(end->p_y - bgn->p_y));
	x = bgn->p_x;
	y = bgn->p_y;
	fdf_putpxl(fdf->img, x, y, fdf_clr(bgn, end, y, bin));
	while (y != end->p_y)
	{
		if (y < end->p_y)
			y ++;
		else if (y > end->p_y)
			y --;
		slope += (2 * abs(end->p_y - bgn->p_y));
		if (slope >= 0)
		{
			if (x < end->p_x)
				x ++;
			else if (x > end->p_x)
				x --;
			slope -= (2 * abs(end->p_y - bgn->p_y));
		}
		fdf_putpxl(fdf->img, x, y, fdf_clr(bgn, end, y, bin));
	}
}
