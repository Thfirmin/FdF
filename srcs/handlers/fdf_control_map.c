/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_control_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 00:48:53 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/17 02:08:03 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_move_map(t_fdf *fdf, int key)
{
	if (key == K_W)
		fdf->set.mv_y += -1;
	else if (key == K_S)
		fdf->set.mv_y += 1;
	if (key == K_A)
		fdf->set.mv_x += -1;
	else if (key == K_D)
		fdf->set.mv_x += 1;
}


void	fdf_rot_map(t_fdf *fdf, int key)
{
	if ((key == K_I) || (key == K_K))
	{
		if (key == K_I)
			fdf->set.rot ++;
		else if (key == K_K)
			fdf->set.rot --;
	}
	if ((key == K_J) || (key == K_L))
	{
		if (key == K_J)
			fdf->set.angle --;
		else if (key == K_L)
			fdf->set.angle ++;
	}
}

void	fdf_resize_map(t_fdf *fdf, int key)
{
	if (key == K_E)
		fdf->set.offset ++;
	else if (key == K_Q)
		fdf->set.offset --;
	else if (key == K_O)
		fdf->set.scale_z ++;
	else if (key == K_U)
		fdf->set.scale_z --;
}
