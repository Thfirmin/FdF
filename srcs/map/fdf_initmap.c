/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_initmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:00:45 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/04 16:31:36 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Read map and take minimum size to window
static void		fdf_get_screen_size(t_fdf *fdf, int *sizex, int *sizey);

// Read values, desassemble heigh and color and mount a point node
static t_pnt	*fdf_build_point(char *vlue, int x_co, int y_co, t_fdf *fdf);

// Read a line of map, desassemble and mount a line map linked list
static char		*fdf_build_line(char *line, int x_co, t_fdf *fdf);

// Initialize map: Read them and build map linked list
void	fdf_initmap(char *pathmap, t_fdf *fdf)
{
	int		fd;
	int		x_co;
	char	*line;
	char	*end;

	fdf->map = 0;
	fd = open (pathmap, O_RDONLY);
	x_co = 0;
	line = (void *)1;
	while(line && ++x_co)
	{
		line = get_next_line (fd);
		ft_bzero((void *)ft_strchr(line, '\n'), 1);
		if ((end = fdf_build_line(line, x_co, fdf)))
			break ;
		free (line);
	}
	fdf_closefile (fd, line);
	if (end)
		fdf_error (end, fdf);
	fdf_get_screen_size(fdf, &fdf->set.s_x, &fdf->set.s_y);
}

static char	*fdf_build_line(char *line, int x_co, t_fdf *fdf)
{
	char	**split;
	int		y_co;
	t_pnt	*point;

	split = ft_split(line, ' ');
	if (!split && line)
		return (strerror(ENOMEM));
	y_co = -1;
	while (line && *(split + ++y_co))
	{
		point = fdf_build_point(*(split + y_co), x_co, (y_co + 1), fdf);
		if (!point)
		{
			fdf_pntclear(&(fdf->map));
			break ;
		}
		fdf_pntadd_back(&(fdf->map), point);
	}
	ft_frsplit(split);
	if (!fdf->map)
		return (strerror(ENOMEM));
	return (0);
}

static t_pnt	*fdf_build_point(char *vlue, int x_co, int y_co, t_fdf *fdf)
{
	t_pnt			*node;
	char			*hex;
	unsigned int	color;

	hex = ft_strchr(vlue, ',');
	if (hex)
	{
		*hex++ = 0;
		color = fdf_htoi(hex);
	}
	else
		color = fdf->set.std_clr;
	node = fdf_pntnew(ft_atoi(vlue), x_co, y_co, color);
	return (node);
}

static void	fdf_get_screen_size(t_fdf *fdf, int *sizex, int *sizey)
{
	t_pnt	*lst;

	lst = fdf_pntlast(fdf->map);
	*sizex = (lst->p_x * fdf->set.p_spc + (2 * fdf->set.border));
	*sizey = (lst->p_y * fdf->set.p_spc + (2 * fdf->set.border));
	if (*sizex < 190)
		*sizex = 190;
}
