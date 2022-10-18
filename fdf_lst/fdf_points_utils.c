/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_points_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 22:58:34 by thfirmin          #+#    #+#             */
/*   Updated: 2022/10/17 23:39:11 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*fdf_pntsnew(int x, int y, int z, int clr)
{
	t_point	*newpnts;

	newpnts = malloc (sizeof(t_point));
	if (!newpnts)
		return (0);
	newpnts->pt_x = x;
	newpnts->pt_y = y;
	newpnts->pt_z = z;
	newpnts->pt_clr = clr;
	newpnts->pt_next = 0;
	return (newpnts);
}

void	fdf_pntsclear(t_point **point)
{
	t_point *next;

	if (!point)
		return ;
	while (*point)
	{
		next = (**point).pt_next;
		free (*point);
		*point = next;
	}
	point = 0;
}

void	fdf_pntsadd_back(t_point **pnt, t_point *newpnt)
{
	t_point	*lst_pnt;

	lst_pnt = fdf_pntslast(*pnt);
	if (!lst_pnt)
		*pnt = newpnt;
	else
		lst_pnt->pt_next = newpnt;
}

t_point	*fdf_pntslast(t_point *pnt)
{
	if (!pnt)
		return (0);
	while (pnt->pt_next)
		pnt = pnt->pt_next;
	return (pnt);
}

int	fdf_pntssize(t_point *pnt)
{
	int	size;

	size = 0;
	while (pnt)
	{
		size ++;
		pnt = pnt->pt_next;
	}
	return (size);
}
