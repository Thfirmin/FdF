/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 16:39:41 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/11 22:34:34 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_mlxinit(t_fdf *fdf);

static void	fdf_std_setting(t_fdf *fdf);

void	fdf_init(char *pathmap, t_fdf *fdf)
{
	printf("passo 1\n");
	fdf->mlx.mlx = mlx_init();
	printf("passo 2\n");
	if (!fdf->mlx.mlx)
		fdf_error(strerror(ENOMEM), fdf);
	printf("passo 3\n");
	fdf_std_setting(fdf);
	printf("passo 4\n");
	fdf_initmap(pathmap, fdf);
	printf("passo 5\n");
	fdf_mlxinit(fdf);
	printf("passo 6\n");
}

static void	fdf_std_setting(t_fdf *fdf)
{
	fdf->set.win_x = FDF_WIN_X;
	fdf->set.win_y = FDF_WIN_Y;
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
	mlx->win = mlx_new_window(mlx->mlx, set->win_x, set->win_y, "FDF");
	if (!mlx->win)
		fdf_error(strerror(ENOMEM), fdf);
	mlx->img = mlx_new_image(mlx->mlx, set->img_x, set->img_y);
	if (!mlx->img)
		fdf_error(strerror(ENOMEM), fdf);
	set->head = mlx_get_data_addr(mlx->img, &set->bpp, &set->llen, &set->endn);
}

