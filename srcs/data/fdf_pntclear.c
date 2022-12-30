/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_pntclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 19:52:18 by thfirmin          #+#    #+#             */
/*   Updated: 2022/12/25 22:04:24 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
