/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init_setting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 23:46:37 by thfirmin          #+#    #+#             */
/*   Updated: 2022/12/30 00:25:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_init_setting(char *pathmap, t_fdf **fdf)
{
	*fdf = ft_calloc(1, sizeof(t_fdf));
	if (!*fdf)
		fdf_error(strerror(ENOMEM), 0);
	fdf_std_settings(fdf);
	fdf_initmap(pathmap, fdf);
	fdf_initmlx(fdf);
}

// Define Standard settings of fdf
void	fdf_std_settings(t_fdf **fdf)
{
	t_config	*conf;

	(**fdf).cnfg = ft_calloc(1, sizeof(t_config));
	if (!(**fdf).cnfg)
		fdf_error(strerror(ENOMEM), fdf);
	conf = (**fdf).cnfg;
	conf->std_color = 0xFFFFFF;
}

void	fdf_initmlx(t_fdf **fdf)
{

	t_mlx	*minilibx;

	(**fdf).minix = ft_calloc(1, sizeof(t_mlx));
	if (!(**fdf).minix)
		fdf_error(strerror(ENOMEM), fdf);
	minilibx = (**fdf).minix;
	minilibx->mlx = mlx_init();
	if (!minilibx->mlx)
		fdf_error(strerror(ENOMEM), fdf);
	minilibx->win = mlx_new_window(minilibx->mlx, (**fdf).cnfg->sz_x * 18, (**fdf).cnfg->sz_y * 18, "FDF");
	mlx_loop(minilibx->mlx);
}