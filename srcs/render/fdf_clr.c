/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_clr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 23:41:42 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/17 01:46:28 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static unsigned int	fdf_get_b(t_pnt *bgn, t_pnt *end, float dist);

static unsigned int	fdf_get_g(t_pnt *bgn, t_pnt *end, float dist);

static unsigned int	fdf_get_r(t_pnt *bgn, t_pnt *end, float dist);

static unsigned int	fdf_get_t(t_pnt *bgn, t_pnt *end, float dist);

unsigned int	fdf_clr(t_pnt *bgn, t_pnt *end, int ap, int bin)
{
	unsigned int	clr;
	float			prct;
	int				aux;

	clr = 0;
	if (!bin)
	{
		aux = abs(end->p_x - bgn->p_x);
		if (!aux)
			aux ++;
		prct = ((abs(ap - bgn->p_x) * 100) / aux);
	}
	else
	{
		aux = abs(end->p_y - bgn->p_y);
		if (!aux)
			aux ++;
		prct = ((abs(ap - bgn->p_y) * 100) / aux);
	}
	clr |= fdf_get_t(bgn, end, prct);
	clr |= fdf_get_r(bgn, end, prct);
	clr |= fdf_get_g(bgn, end, prct);
	clr |= fdf_get_b(bgn, end, prct);
	return (clr);
}

static unsigned int	fdf_get_t(t_pnt *bgn, t_pnt *end, float dist)
{
	float			dt;
	int				diff;
	unsigned int	clr;

	clr = ((bgn->clr >> 24) & 0xFF);
	if (clr > ((end->clr >> 24) & 0xFF))
		dt = ((bgn->clr >> 24) & 0xFF) - ((end->clr >> 24) & 0xFF);
	else
		dt = ((end->clr >> 24) & 0xFF) - ((bgn->clr >> 24) & 0xFF);
	diff = floor(dt * (dist / 100));
	if (clr > ((end->clr >> 24) & 0xFF))
		clr -= diff;
	else if (clr < ((end->clr >> 24) & 0xFF))
		clr += diff;
	return (clr << 24);
}

static unsigned int	fdf_get_r(t_pnt *bgn, t_pnt *end, float dist)
{
	float			dt;
	int				diff;
	unsigned int	clr;

	clr = ((bgn->clr >> 16) & 0xFF);
	if (clr > ((end->clr >> 16) & 0xFF))
		dt = ((bgn->clr >> 16) & 0xFF) - ((end->clr >> 16) & 0xFF);
	else
		dt = ((end->clr >> 16) & 0xFF) - ((bgn->clr >> 16) & 0xFF);
	diff = floor(dt * (dist / 100));
	if (clr > ((end->clr >> 16) & 0xFF))
		clr -= diff;
	else if (clr < ((end->clr >> 16) & 0xFF))
		clr += diff;
	return (clr << 16);
}

static unsigned int	fdf_get_g(t_pnt *bgn, t_pnt *end, float dist)
{
	float			dt;
	int				diff;
	unsigned int	clr;

	clr = ((bgn->clr >> 8) & 0xFF);
	if (clr > ((end->clr >> 8) & 0xFF))
		dt = ((bgn->clr >> 8) & 0xFF) - ((end->clr >> 8) & 0xFF);
	else
		dt = ((end->clr >> 8) & 0xFF) - ((bgn->clr >> 8) & 0xFF);
	diff = floor(dt * (dist / 100));
	if (clr > ((end->clr >> 8) & 0xFF))
		clr -= diff;
	else if (clr < ((end->clr >> 8) & 0xFF))
		clr += diff;
	return (clr << 8);
}

static unsigned int	fdf_get_b(t_pnt *bgn, t_pnt *end, float dist)
{
	float			dt;
	int				diff;
	unsigned int	clr;

	clr = (bgn->clr & 0xFF);
	if (clr > (end->clr & 0xFF))
		dt = (bgn->clr & 0xFF) - (end->clr & 0xFF);
	else
		dt = (end->clr & 0xFF) - (bgn->clr & 0xFF);
	diff = floor(dt * (dist / 100));
	if (clr > (end->clr & 0xFF))
		clr -= diff;
	else if (clr < (end->clr & 0xFF))
		clr += diff;
	return (clr);
}
