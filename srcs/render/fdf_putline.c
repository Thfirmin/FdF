/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_putline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 23:34:07 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/15 23:50:06 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_plotpxl(t_fdf *fdf, t_pnt *bgn, t_pnt *end, int bin);

void	fdf_putline(t_fdf *fdf, t_pnt *bgn, t_pnt *end)
{
	int	dx;
	int	dy;
	int	bin;

	dx = abs(end->p_x - bgn->p_x);
	dy = abs(end->p_y - bgn->p_y);
	bin = !(dx > dy);
	if (!bin)
		fdf_putpxl(fdf->img, bgn->p_x, bgn->p_y, fdf_clr(bgn, end, dx, bin));
	else
		fdf_putpxl(fdf->img, bgn->p_x, bgn->p_y, fdf_clr(bgn, end, dy, bin));
	fdf_plotpxl(fdf, bgn, end, bin);
}

static void	fdf_plotpxl(t_fdf *fdf, t_pnt *bgn, t_pnt *end, int bin)
{
	int	slope;
	int	dx;
	int	dy;

	if (!bin)
	{
		dx = abs(end->p_x - bgn->p_x);
		dy = abs(end->p_y - bgn->p_y);
	}
	else
	{
		dx = abs(end->p_y - bgn->p_y);
		dy = abs(end->p_x - bgn->p_x);
	}
	slope = (2 * dy - dx);
	while ((bgn->p_x != end->p_x) || (bgn->p_y != end->p_y))
	{
		if (!bin && (end->p_x != bgn->p_x))
			bgn->p_x += ((end->p_x - bgn->p_x) / abs(end->p_x - bgn->p_x));
		else  if (bin && (end->p_y != bgn->p_y))
			bgn->p_y += ((end->p_y - bgn->p_y) / abs(end->p_y - bgn->p_y));
		slope += (2 * dy);
		if (slope >= 0)
		{
			if (!bin && (end->p_y != bgn->p_y))
				bgn->p_y += ((end->p_y - bgn->p_y) / abs(end->p_y - bgn->p_y));
			else if (bin && (end->p_x != bgn->p_x))
				bgn->p_x += ((end->p_x - bgn->p_x) / abs(end->p_x - bgn->p_x));
			slope -= (2 * dx); 
		}
		fdf_putpxl(fdf->img, bgn->p_x, bgn->p_y, fdf_clr(bgn, end, dx, bin));
	}
}
