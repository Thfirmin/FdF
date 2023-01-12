/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_putline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 23:12:42 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/11 22:40:43 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_plotpxl(t_fdf *fdf, t_pnt *bgn, t_pnt *end, int bin);

static void	fdf_block_screen(t_fdf *fdf, t_pnt *pnt);

void	fdf_putline(t_fdf *fdf, t_pnt *bgn, t_pnt *end)
{
	int	dx;
	int	dy;
	int	bin;

	fdf_block_screen(fdf, bgn);
	fdf_block_screen(fdf, end);
	dx = abs(end->p_x - bgn->p_x);
	dy = abs(end->p_y - bgn->p_y);
	bin = !(dx > dy);
	fdf_putpxl(fdf->set, bgn->p_x, bgn->p_y, fdf_clr_pass(bgn, end, dx, bin));
	fdf_plotpxl(fdf, bgn, end, bin);
}

static void	fdf_block_screen(t_fdf *fdf, t_pnt *pnt)
{
	if ((pnt->p_x < 0) || (pnt->p_x >= fdf->set.img_x))
	{
		if (pnt->p_x < 0)
			pnt->p_x = 0;
		else
			pnt->p_x = (fdf->set.img_x - 1);
	}
	if ((pnt->p_y < 0) || (pnt->p_y >= fdf->set.img_y))
	{
		if (pnt->p_y < 0)
			pnt->p_y = 0;
		else
			pnt->p_y = (fdf->set.img_y - 1);
	}
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
		fdf_putpxl(fdf->set, bgn->p_x, bgn->p_y, fdf_clr_pass(bgn, end, dx, bin));
	}
}
