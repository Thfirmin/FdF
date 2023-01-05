/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_pntdata.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:02:06 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/03 20:03:57 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pnt	*fdf_pntnew(int hgh, int x, int y, unsigned int clr)
{
	t_pnt	*newpnt;

	newpnt = ft_calloc(1, sizeof(t_pnt));
	if (!newpnt)
		return (0);
	(*newpnt).hgh = hgh;
	(*newpnt).p_x = x;
	(*newpnt).p_y = y;
	(*newpnt).clr = clr;
	(*newpnt).next = 0;
	return (newpnt);
}

void	fdf_pntadd_back(t_pnt **map, t_pnt *point)
{
	t_pnt	*lstpnt;

	lstpnt = *map;
	while (lstpnt && (*lstpnt).next)
		lstpnt = (*lstpnt).next;
	if (!lstpnt)
		*map = point;
	else
		lstpnt->next = point;
}

t_pnt	*fdf_pntlast(t_pnt *map)
{
	while (map && map->next)
		map = map->next;
	return (map);
}

void	fdf_pntclear(t_pnt **map)
{
	t_pnt	*nxtpnt;

	if (!map)
		return ;
	while (*map)
	{
		nxtpnt = (**map).next;
		free(*map);
		*map = nxtpnt;
	}
}
