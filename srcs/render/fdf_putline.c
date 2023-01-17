/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_putline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 23:34:07 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/17 00:25:09 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_bresenhamx(t_fdf *fdf, t_pnt *bgn, t_pnt *end);

static void	fdf_bresenhamy(t_fdf *fdf, t_pnt *bgn, t_pnt *end);

void	fdf_putline(t_fdf *fdf, t_pnt *bgn, t_pnt *end)
{
	int	bin;
	int	dx;
	int	dy;

	dx = abs(end->p_x - bgn->p_x);
	dy = abs(end->p_y - bgn->p_y);
	bin = !(dx > dy);
	if (!bin)
		fdf_bresenhamx(fdf, bgn, end);
	else
		fdf_bresenhamy(fdf, bgn, end);
}

static void	fdf_bresenhamx(t_fdf *fdf, t_pnt *bgn, t_pnt *end)
{
	int	m_new;
	int	slope;
	int	x;
	int	y;

	m_new = (2 * abs(end->p_y - bgn->p_y));
	slope = (m_new - abs(end->p_x - bgn->p_x));
	x = bgn->p_x;
	y = bgn->p_y;
	fdf_putpxl(fdf->img, x, y, 0xFFFFFF);
	while (x != end->p_x)
	{
		if (x < end->p_x)
			x ++;
		else if (x > end->p_x)
			x --;
		slope += m_new;
		if (slope >= 0)
		{
			if (y < end->p_y)
				y ++;
			else if (y > end->p_y)
				y --;
			slope -= (2 * abs(end->p_x - bgn->p_x));
		}
		fdf_putpxl(fdf->img, x, y, 0xFFFFFF);
	}	
}

static void	fdf_bresenhamy(t_fdf *fdf, t_pnt *bgn, t_pnt *end)
{
	int	m_new;
	int	slope;
	int	x;
	int	y;

	m_new = (2 * abs(end->p_x - bgn->p_x));
	slope = (m_new - abs(end->p_y - bgn->p_y));
	x = bgn->p_x;
	y = bgn->p_y;
	fdf_putpxl(fdf->img, x, y, 0xFFFFFF);
	while (y != end->p_y)
	{
		if (y < end->p_y)
			y ++;
		else if (y > end->p_y)
			y --;
		slope += m_new;
		if (slope >= 0)
		{
			if (x < end->p_x)
				x ++;
			else if (x > end->p_x)
				x --;
			slope -= (2 * abs(end->p_y - bgn->p_y));
		}
		fdf_putpxl(fdf->img, x, y, 0xFFFFFF);
	}
}
