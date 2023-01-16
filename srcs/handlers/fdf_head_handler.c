/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_head_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 01:38:42 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/13 22:48:04 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_head_handler(t_fdf *fdf)
{
	if (!fdf)
		return ;
	if (fdf->mlx.img)
		mlx_destroy_image(fdf->mlx.mlx, fdf->mlx.img);
	if (fdf->mlx.win)
		mlx_destroy_window(fdf->mlx.mlx, fdf->mlx.win);
	if (fdf->mlx.mlx)
		free(fdf->mlx.mlx);
	if (fdf->map)
		fdf_pntclear(&fdf->map);
}
