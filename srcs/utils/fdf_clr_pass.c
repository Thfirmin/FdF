/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_clr_pass.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 02:10:00 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/10 04:57:27 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	fdf_get_b(t_point *bgn, t_point *end, float dist);

static int	fdf_get_g(t_point *bgn, t_point *end, float dist);

static int	fdf_get_r(t_point *bgn, t_point *end, float dist);

static int	fdf_get_t(t_point *bgn, t_point *end, float dist);

int	fdf_clr_pass(t_point *bgn, t_point *end, int dp, int bin)
{
	int	clr;
	float	dist;

	clr = 0;
	if (!bin)
		dist = (dp - abs(end->x - bgn->x));
	else
		dist = (dp - abs(end->y - bgn->y));
	dist = ((dist * 100) / dp);
	clr |= fdf_get_t(bgn, end, dist);
	clr |= fdf_get_r(bgn, end, dist);
	clr |= fdf_get_g(bgn, end, dist);
	clr |= fdf_get_b(bgn, end, dist);
	return (clr);
}

static int	fdf_get_t(t_point *bgn, t_point *end, float dist)
{
	float	dt;
	int		diff;
	int		clr;

	clr = ((bgn->clr >> 24) & 0xFF);
	dt = abs(((end->clr >> 24) & 0xFF) - ((bgn->clr >> 24) & 0xFF));
	diff = floor(dt * (dist / 100));
	if (clr > ((end->clr >> 24) & 0xFF))
		clr -= diff;
	else if (clr < ((end->clr >> 24) & 0xFF))
		clr += diff;
	return (clr << 24);
}

static int	fdf_get_r(t_point *bgn, t_point *end, float dist)
{
	float	dt;
	int		diff;
	int		clr;

	clr = ((bgn->clr >> 16) & 0xFF);
	dt = abs(((end->clr >> 16) & 0xFF) - ((bgn->clr >> 16) & 0xFF));
	diff = floor(dt * (dist / 100));
	if (clr > ((end->clr >> 16) & 0xFF))
		clr -= diff;
	else if (clr < ((end->clr >> 16) & 0xFF))
		clr += diff;
	return (clr << 16);
}

static int	fdf_get_g(t_point *bgn, t_point *end, float dist)
{
	float	dt;
	int		diff;
	int		clr;

	clr = ((bgn->clr >> 8) & 0xFF);
	dt = abs(((end->clr >> 8) & 0xFF) - ((bgn->clr >> 8) & 0xFF));
	diff = floor(dt * (dist / 100));
	if (clr > ((end->clr >> 8) & 0xFF))
		clr -= diff;
	else if (clr < ((end->clr >> 8) & 0xFF))
		clr += diff;
	return (clr << 8);
}

static int	fdf_get_b(t_point *bgn, t_point *end, float dist)
{
	float	dt;
	int		diff;
	int		clr;

	clr = (bgn->clr & 0xFF);
	dt = abs((end->clr & 0xFF) - (bgn->clr & 0xFF));
	diff = floor(dt * (dist / 100));
	if (clr > (end->clr & 0xFF))
		clr -= diff;
	else if (clr < (end->clr & 0xFF))
		clr += diff;
	return (clr);
}
