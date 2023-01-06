/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_fdfdata.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:04:08 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/05 18:21:34 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_fdfclear(t_fdf *fdf)
{
	if (!fdf)
		return ;
	if (fdf->mlx.img)
		mlx_destroy_image(fdf->mlx.mlx, fdf->mlx.img);
	if (fdf->mlx.win)
		mlx_destroy_window(fdf->mlx.mlx, fdf->mlx.win);
	if (fdf->mlx.mlx)
		free (fdf->mlx.mlx);
	if (fdf->map)
		fdf_pntclear(&fdf->map);
}
