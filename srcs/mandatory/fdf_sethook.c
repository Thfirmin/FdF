/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_sethook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 23:35:31 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/04 16:47:11 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_sethook(t_fdf *fdf)
{
	mlx_hook(fdf->mlx.win, 3, 2, fdf_keyhandler, fdf);
	mlx_hook(fdf->mlx.win, 17, 0, fdf_cross, fdf);
}
