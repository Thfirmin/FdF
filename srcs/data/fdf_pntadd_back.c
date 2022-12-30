/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_pntadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 19:52:21 by thfirmin          #+#    #+#             */
/*   Updated: 2022/12/25 22:41:46 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
