/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_putline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 23:12:42 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/10 04:15:14 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_plotpxl(t_fdf *fdf, t_point *bgn, t_point *end, int bin);

static void	fdf_block_screen(t_fdf *fdf, t_point *pnt);

void	fdf_putline(t_fdf *fdf, t_point *bgn, t_point *end)
{
	int	dx;
	int	dy;

	fdf_block_screen(fdf, bgn);
	fdf_block_screen(fdf, end);
	dx = abs(end->x - bgn->x);
	dy = abs(end->y - bgn->y);
	if (dx > dy)
	{
		fdf_putpxl(fdf->set, bgn->x, bgn->y, fdf_clr_pass(bgn, end, dx, 0));
		fdf_plotpxl(fdf, bgn, end, 0);
	}
	else
	{
		fdf_putpxl(fdf->set, bgn->x, bgn->y, fdf_clr_pass(bgn, end, dx, 1));
		fdf_plotpxl(fdf, bgn, end, 1);
	}
}

static void	fdf_block_screen(t_fdf *fdf, t_point *pnt)
{
	if ((pnt->x < 0) || (pnt->x >= fdf->set.s_x))
	{
		if (pnt->x < 0)
			pnt->x = 0;
		else
			pnt->x = (fdf->set.s_x - 1);
	}
	if ((pnt->y < 0) || (pnt->y >= fdf->set.s_y))
	{
		if (pnt->y < 0)
			pnt->y = 0;
		else
			pnt->y = (fdf->set.s_y - 1);
	}
}

static void	fdf_plotpxl(t_fdf *fdf, t_point *bgn, t_point *end, int bin)
{
	int	slope;
	int	dx;
	int	dy;

	if (!bin)
	{
		dx = abs(end->x - bgn->x);
		dy = abs(end->y - bgn->y);
	}
	else
	{
		dx = abs(end->y - bgn->y);
		dy = abs(end->x - bgn->x);
	}
	slope = (2 * dy - dx);
	while ((bgn->x != end->x) || (bgn->y != end->y))
	{
		if (!bin && (end->x != bgn->x))
			bgn->x += ((end->x - bgn->x) / abs(end->x - bgn->x));
		else  if (bin && (end->y != bgn->y))
			bgn->y += ((end->y - bgn->y) / abs(end->y - bgn->y));
		slope += (2 * dy);
		if (slope >= 0)
		{
			if (!bin && (end->y != bgn->y))
				bgn->y += ((end->y - bgn->y) / abs(end->y - bgn->y));
			else if (bin && (end->x != bgn->x))
				bgn->x += ((end->x - bgn->x) / abs(end->x - bgn->x));
			slope -= (2 * dx); 
		}
		fdf_putpxl(fdf->set, bgn->x, bgn->y, fdf_clr_pass(bgn, end, dx, bin));
	}
}
