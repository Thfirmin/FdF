/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:57:00 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/17 21:01:06 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		fdf_settupmap(t_fdf *fdf);

static void	fdf_initializefdf(t_fdf *fdf, int argc, char *argv[]);

static void	fdf_validmap(int argc, char *argv[]);

int	main(int argc, char *argv[])
{
	t_fdf	fdf;

	fdf_validmap(argc, argv);
	fdf_initializefdf(&fdf, argc, argv);
	fdf_init(&fdf, argv[1]);
	fdf_hooks_handler(&fdf);
	mlx_loop_hook(fdf.mlx.mlx, fdf_render_map, &fdf);
	mlx_loop(fdf.mlx.mlx);
	return (0);
}

static void	fdf_validmap(int argc, char *argv[])
{
	char	*dot;
	int		fd;

	if ((argc < 2) || (argc > 4))
		fdf_error_handler("Usage: ./fdf <filename> [ case_size z_size ]", 0);
	dot = ft_strrchr(argv[1], '.');
	if (!dot || dot == argv[1])
		fdf_error_handler("Invalid map: Only format <filename>.fdf", 0);
	else if (ft_strncmp(dot, ".fdf", 5))
		fdf_error_handler("Invalid map: Extension .fdf only", 0);
	fd = open(argv[1], O_RDONLY);
	if (read(fd, 0, 0) < 0)
		fdf_error_handler("Invalid map: Inexistent or non-readable map", 0);
	close(fd);
}

static void	fdf_initializefdf(t_fdf *fdf, int argc, char *argv[])
{
	fdf->mlx.mlx = 0;
	fdf->mlx.win = 0;
	fdf->mlx.img = 0;
	fdf->map = 0;
	fdf->set.std_clr = 0x00FFFFFF;
	fdf->set.offset = 0;
	fdf->set.scale_z = 0;
	if (argc >= 3)
		fdf->set.offset = ft_atoi(argv[2]);
	if (argc >= 4)
		fdf->set.scale_z = ft_atoi(argv[3]);
	if (!fdf->set.offset)
		fdf->set.offset = 15;
	if (!fdf->set.scale_z)
		fdf->set.scale_z = 1;
	fdf->set.angle = 0;
	fdf->set.rot = 90;
	fdf->set.mv_x = 0;
	fdf->set.mv_y = 0;
}

void	fdf_settupmap(t_fdf *fdf)
{
	fdf->set.offset = 15;
	fdf->set.scale_z = 1;
	fdf->set.angle = -45;
	fdf->set.rot = 228;
	fdf->set.mv_x = 0;
	fdf->set.mv_y = 0;
}
