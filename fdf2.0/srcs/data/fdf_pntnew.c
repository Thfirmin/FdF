/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_pntnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 19:52:14 by thfirmin          #+#    #+#             */
/*   Updated: 2022/12/27 23:31:11 by thfirmin         ###   ########.fr       */
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
