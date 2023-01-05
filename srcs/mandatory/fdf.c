/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 16:39:41 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/04 16:25:46 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_mlxinit(t_fdf *fdf);

static void	fdf_std_setting(t_fdf *fdf);

void	fdf_init(char *pathmap, t_fdf *fdf)
{
	fdf->mlx.mlx = mlx_init();
	if (!fdf->mlx.mlx)
		fdf_error(strerror(ENOMEM), fdf);
	fdf_std_setting(fdf);
	fdf_initmap(pathmap, fdf);
	fdf_mlxinit(fdf);
}

static void	fdf_std_setting(t_fdf *fdf)
{
	fdf->set.std_clr = 0xFFFFFF;
	fdf->set.border = 10;
	fdf->set.p_spc = 18;
}

static void	fdf_mlxinit(t_fdf *fdf)
{
	t_mlx	*mlx;
	t_set	*set;

	mlx = &fdf->mlx;
	set = &fdf->set;
	mlx->win = 0;
	mlx->img = 0;
	mlx->win = mlx_new_window(mlx->mlx, set->s_x, set->s_y, "FDF");
	if (!mlx->win)
		fdf_error(strerror(ENOMEM), fdf);
	mlx->img = mlx_new_image(mlx->mlx, set->s_x, set->s_y);
	if (!mlx->img)
		fdf_error(strerror(ENOMEM), fdf);
	set->head = mlx_get_data_addr(mlx->img, &set->bpp, &set->llen, &set->endn);
}

