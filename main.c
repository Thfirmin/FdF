#include "libft.h"
#include "mlx.h"
#include "get_next_line.h"
#include <stdio.h>

typedef struct	s_data{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_data;

typedef struct s_fdf{
	void	*mlx;
	void	*win;
	t_data	img;
}			t_fdf;

void	print_square(t_data *data, int x, int y, int size, int color);

void	my_pixel_put(t_data *data, int x, int y, int color);

int		pressed(int key, t_fdf *fdf)
{
	if (key == 65307)
	{
		mlx_destroy_image(fdf->mlx, fdf->img.img);
		mlx_destroy_window(fdf->mlx, fdf->win);
		mlx_destroy_display(fdf->mlx);
		exit (0);
	}
	printf ("pressed!\nkey = %d\n", key);
	return (1);
}

int		solted(int num, t_fdf *fdf)
{
	(void) fdf;
	printf ("solted!\nkey = %d\n", num);
	return (1);
}

int		voila(int num, t_fdf *fdf)
{
	(void) fdf;
	printf("voila!\nKILA = %d\n", num);
	return (1);

}

int	main(void)
{
	t_fdf	fdf;
	int		x = 442;
	int		y = 342;

	// Create a instance of mlx
	fdf.mlx = mlx_init();

	// get size of screen
	//mlx_get_screen_size(mlx, &x, &y);

	// Create a windows of mlx
	fdf.win = mlx_new_window(fdf.mlx, x, y, "FDF");

	// HOOKS - EVENT
	// ON_KEYDOWN = 2 x 1L<<0	int (*f)(int keycode, void *param)
	// ON_KEYUP = 3 x 1L<<1		int (*f)(int keycode, void *param)
	// ON_MOUSEDOWN = 4 x 1L<<2	int (*f)(int button, int x, int y, void *param)
	// ON_MOUSEUP = 5 x 1L<<3	int (*f)(int button, int x, int y, void *param)
	// ON_MOUSEMOVE = 6 x ?	int (*f)(int x, int y, void *param)
	// ON_EXPOSE = 12 x ?	int (*f)(void *param)
	// ON_DESTROY = 17 x ?	int (*f)(void *param)
	mlx_hook(fdf.win, 2, 0, pressed, &fdf);
	mlx_hook(fdf.win, 3, 0, solted, &fdf);
	mlx_hook(fdf.win, 17, 0, voila, &fdf);

	// Create a new image in window of mlx
	fdf.img.img = mlx_new_image(fdf.mlx, x, y);

	// Take info of image
	fdf.img.addr = mlx_get_data_addr(fdf.img.img, &fdf.img.bpp, &fdf.img.line_len, &fdf.img.endian);
	
	// Print in image
	print_square(&fdf.img, (x /2), (y / 2), 100, 0x00FF0000);

	// Put the image in window
	mlx_put_image_to_window(fdf.mlx, fdf.win, fdf.img.img, 0, 0);

	// Clear all content of window
	mlx_clear_window(fdf.mlx, fdf.win);

	// Keep mlx activated
	mlx_loop(fdf.mlx);
	return (0);
}

void	my_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void	print_square(t_data *data, int x, int y, int size, int color)
{
	for (int i = 0; i <= size; i ++)
	{
		my_pixel_put(data, (x + i), y, color);
		my_pixel_put(data, x, (y + i), color);
		my_pixel_put(data, (x + size), (y + i), color);
		my_pixel_put(data, (x + i), (y + size), color);
	}
}
