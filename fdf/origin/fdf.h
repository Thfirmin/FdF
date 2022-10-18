#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include <fcntl.h>
# include "mlx.h"

typedef struct s_window
{
	void	*mlx;
	void	*win;
	int		win_x;
	int		win_y;
}			t_window;

typedef struct s_ponto
{
	int	ptx;
	int	pty;
}		t_ponto;

enum e_keymap
{
	KEY_ESC = 53,
	KEY_W	= 12,
	CLOSE_BUTTON = 17
};

void	print_line(t_ponto pta, t_ponto ptb, int color, t_window *ptr);

void	fill_area(t_ponto pta, t_ponto ptb, int color, t_window *ptr);
#endif
