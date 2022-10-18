/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 20:20:08 by thfirmin          #+#    #+#             */
/*   Updated: 2022/09/25 06:37:53 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	argument_validate(int argc, char *argv[]);

int	main(int argc, char *argv[])
{
	int			fd;
	int			length[2];
	void		*mlx;
	void		*win;
	t_point		*pnt;
	t_window	*fdf;

	fd = argument_validate(argc, argv);
	pnt = fdf_map_analysis(fd);
	length[0] = window_length(pnt, 0);
	length[1] = window_length(pnt, 1);
	printf ("len_x = %d\nlen_y = %d\n", length[0], length[1]);
	mlx = mlx_init();
	win = mlx_new_window(mlx, length[0], length[1], "FDF");
	fdf = fdf_winnew(mlx, win, length, pnt);
	mlx_key_hook(fdf->win, window_key, fdf);
	mlx_hook(fdf->win, CLOSE_BUTTON, 0, close_window, fdf);
	mlx_loop_hook(fdf->mlx, draw_window, &fdf);
	mlx_loop(fdf->mlx);
	return (0);
}

// Testing file argument, open it and validate existent file
static int	argument_validate(int argc, char *argv[])
{
	int	fd;

	(void)argv;
	if (argc != 2)
		invalid_argument();
	fd = open(argv[1], O_RDONLY);
	if ((read(fd, 0, 0)) < 0)
		file_not_found(argv[1]);
	return (fd);
}
