/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_paint_tools.c                                 :+:     :+:            */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 01:58:15 by thfirmin          #+#    #+#             */
/*   Updated: 2022/09/21 05:26:49 by Thinotsuki   ###     ###.br              */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_line(t_ponto pta, t_ponto ptb, int color, t_window *ptr)
{
	while ((pta.ptx != ptb.ptx) || (pta.pty != ptb.pty))
	{
		mlx_pixel_put(ptr->mlx, ptr->win, pta.ptx, pta.pty, color);
		if (pta.ptx > ptb.ptx)
			pta.ptx--;
		else if (pta.ptx < ptb.ptx)
			pta.ptx ++;
		if (pta.pty > ptb.pty)
			pta.pty --;
		else if (pta.pty < ptb.pty)
			pta.pty ++;
	}
}

void	fill_area(t_ponto pta, t_ponto ptb, int color, t_window *ptr)
{
	t_ponto pnt_b;

	while ((pta.ptx != ptb.ptx) || (pta.pty != ptb.pty))
	{
		pnt_b = ptb;
		pnt_b.pty = pta.pty;
		print_line(pta, pnt_b, color, ptr);
		pnt_b.pty = ptb.pty;
		pnt_b.ptx = pta.ptx;
		print_line(pta, pnt_b, color, ptr);

		if (pta.ptx > ptb.ptx)
			pta.ptx--;
		else if (pta.ptx < ptb.ptx)
			pta.ptx ++;
		if (pta.pty > ptb.pty)
			pta.pty --;
		else if (pta.pty < ptb.pty)
			pta.pty ++;
	}
}
