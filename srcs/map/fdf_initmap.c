/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_initmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:00:45 by thfirmin          #+#    #+#             */
/*   Updated: 2022/12/29 13:45:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Read values, desassemble heigh and color and mount a point node
static t_pnt	*fdf_build_point(char *vlue, int x_co, int y_co, t_fdf *fdf);

// Read a line of map, desassemble and mount a line map linked list
static char		*fdf_build_line(char *line, int x_co, t_fdf *fdf);

// Initialize map: Read them and build map linked list
void	fdf_initmap(char *pathmap, t_fdf **fdf)
{
	int		fd;
	int		x_co;
	char	*line;
	char	*end;
	t_pnt	*lst;

	fd = open (pathmap, O_RDONLY);
	x_co = 0;
	line = (void *)1;
	while(line && ++x_co)
	{
		line = get_next_line (fd);
		ft_bzero((void *)ft_strchr(line, '\n'), 1);
		if ((end = fdf_build_line(line, x_co, *fdf)))
			break ;
		free (line);
	}
	fdf_closefile (fd, line);
	if (end)
		fdf_error (end, fdf);
	lst = fdf_pntlast((*fdf)->map);
	(*fdf)->cnfg->sz_x = lst->p_x;
	(*fdf)->cnfg->sz_y = lst->p_y;
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
		color = fdf->cnfg->std_color;
	node = fdf_pntnew(ft_atoi(vlue), x_co, y_co, color);
	return (node);
}
