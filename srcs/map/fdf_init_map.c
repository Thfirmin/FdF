/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 01:49:39 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/17 16:12:12 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		fdf_takevlue_trgb(char *hex, t_fdf *fdf);

static t_pnt	*fdf_build_point(char *vlue, int x_co, int y_co, t_fdf *fdf);

static int		fdf_build_line(t_fdf *fdf, char *line, int y_co);

void	fdf_init_map(t_fdf *fdf, char *pathmap)
{
	int		fd;
	int		y_co;
	char	*line;

	fd = open(pathmap, O_RDONLY);
	y_co = 0;
	while (y_co > -1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_bzero((void *)ft_strchr(line, '\n'), 1);
		y_co = fdf_build_line(fdf, line, y_co);
		free(line);
		if (y_co > -1)
			y_co ++;
	}
	get_next_line(-1);
	close(fd);
	if (!y_co)
		fdf_error_handler("Error: Map creat has been failed", fdf);
}

static int	fdf_build_line(t_fdf *fdf, char *line, int y_co)
{
	int			x_co;
	char		**split;
	static int	memo = -1;
	t_pnt		*point;

	split = ft_split(line, ' ');
	x_co = -1;
	while (split && *(split + ++x_co))
	{
		point = fdf_build_point(*(split + x_co), x_co, y_co, fdf);
		if (!point)
		{
			ft_frsplit(split);
			return (-1);
		}
		fdf_pntadd_back(&(fdf->map), point);
	}
	ft_frsplit(split);
	if (memo < 0)
		memo = x_co;
	else if (memo != x_co)
		return (-1);
	return (y_co);
}

static t_pnt	*fdf_build_point(char *vlue, int x_co, int y_co, t_fdf *fdf)
{
	t_pnt	*node;
	char	*hex;
	int		color;

	hex = ft_strchr(vlue, ',');
	if (hex)
	{
		*hex++ = 0;
		if ((*hex == '0') && (*(hex + 1) == 'x' || *(hex + 1) == 'X'))
			color = fdf_takevlue_trgb(hex + 2, fdf);
		else
			color = fdf->set.std_clr;
	}
	else
		color = fdf->set.std_clr;
	node = fdf_pntnew(ft_atoi(vlue), x_co, y_co, color);
	return (node);
}

static int	fdf_takevlue_trgb(char *hex, t_fdf *fdf)
{
	int		clr;
	short	i;
	short	x;

	clr = 0;
	i = ft_strlen(hex);
	if (!(i == 8 || i == 6))
		return (fdf->set.std_clr);
	x = -1;
	while (++x < i)
	{
		clr *= 16;
		if (*(hex + x) >= '0' && *(hex + x) <= '9')
			clr += (*(hex + x) - '0');
		else if (*(hex + x) >= 'A' && *(hex + x) <= 'F')
			clr += (*(hex + x) - 'A' + 10);
		else
			clr += 15;
	}
	return (clr);
}
