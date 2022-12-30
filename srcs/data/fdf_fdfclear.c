/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_fdfclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:16:43 by marvin            #+#    #+#             */
/*   Updated: 2022/12/29 14:16:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_fdfclear(t_fdf **fdf)
{
	if (!fdf)
		return ;
	if ((**fdf).cnfg)
		free((**fdf).cnfg);
	if ((**fdf).map)
		fdf_pntclear(&(**fdf).map);
	//if ((**fdf).minix)
	//	fdf_mlxclear(&(**fdf).minix);
	free(*fdf);
}