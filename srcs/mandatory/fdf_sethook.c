/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_sethook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 23:35:31 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/09 18:33:31 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_sethook(t_fdf *fdf)
{
	mlx_hook(fdf->mlx.win, 2, 1L<<0, fdf_keyhandler, fdf);
	mlx_hook(fdf->mlx.win, 17, 0, fdf_cross, fdf);
}
