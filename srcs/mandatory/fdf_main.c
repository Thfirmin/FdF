/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:19:46 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/10 00:45:47 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_fdf	fdf;

	if (argc != 2)
		fdf_error(strerror(EINVAL), 0);
	fdf_is_validmap(argv[1]);
	fdf_init(argv[1], &fdf);
	fdf_sethook(&fdf);
	mlx_loop_hook(fdf.mlx.mlx, fdf_printfdf, &fdf);
	mlx_loop(fdf.mlx.mlx);
	fdf_fdfclear(&fdf);
	return (0);
}
