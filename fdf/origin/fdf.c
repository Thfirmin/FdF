/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 06:56:09 by thfirmin          #+#    #+#             */
/*   Updated: 2022/09/22 21:04:24 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*int	main(int argc, char *argv[])
{
	int		fd;
	char	*line;
	
	if (argc != 2)
		return (2);
	fd = open(argv[1], O_RDONLY);
	do
	{
		line = get_next_line(fd);
		ft_printf("%s", line);
		if (line)
			free(line);
	}
	while (line);
}
*/

int	close_window(void);

int	take_key(int keycode);

int	draw_window(t_window *ptr);

int	main(void)
{
	t_window	ptr;

	ptr.win_x = 800;
	ptr.win_y = 600;
	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, ptr.win_x, ptr.win_y, "FDF");
	mlx_key_hook(ptr.win, take_key, (void *)0);
	mlx_hook(ptr.win, CLOSE_BUTTON, 0, close_window, (void *)0);
	mlx_loop_hook(ptr.mlx, draw_window, &ptr);
	mlx_loop(ptr.mlx);
	return (0);
}


int	take_key(int keycode)
{
	if (keycode == KEY_ESC)
		close_window();
	return (1);
}

int	close_window(void)
{
	exit (0);
}

int	draw_window(t_window *ptr)
{
	t_ponto	ptn[] = {
		{25, 25},
		{100,25},
		{25,45},
		{100,45},

	};
	print_line(ptn[0], ptn[1], 0x00FF0000, ptr);
	//print_line(ptn[1], ptn[3], 0x00FF0000, ptr);
	//print_line(ptn[2], ptn[3], 0x00FF0000, ptr);
	//print_line(ptn[2], ptn[1], 0x00FF0000, ptr);
	//print_line(ptn[0], ptn[3], 0x00FF0000, ptr);
	return (0);
}
