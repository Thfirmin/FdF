/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_window_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 05:44:44 by thfirmin          #+#    #+#             */
/*   Updated: 2022/09/25 06:45:06 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	window_length(t_point *pnt, int axis)
{
	t_point	*lstnode;

	lstnode = fdf_pntlast(pnt);
	if (!axis)
		return ((lstnode->pt_x + 1) * 28);
	else
		return ((lstnode->pt_y + 1) * 28);
}

int	close_window(t_window *fdf)
{
	fdf_pntclear(&fdf->fdf_pnt);
	exit (0);
}

int	window_key(int keycode, t_window *fdf)
{
	if (keycode == KEY_ESC)
		close_window(fdf);
	return (0);
}

int	draw_window(t_window *fdf)
{
	(void)fdf;
	return (0);
}
