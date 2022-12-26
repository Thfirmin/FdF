/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_initmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:00:45 by thfirmin          #+#    #+#             */
/*   Updated: 2022/12/26 01:13:21 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pnt	*fdf_initmap(char *pathmap)
{
	t_pnt	*map;
	char	*line;
	int		i;
	int		fd;

	map = 0;
	i = 0;
	fd = open(pathmap, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		fdf_pntadd_back(&map, fdf_pntnew(0, i, 0, 0));
		i ++;
		free (line);
	}
	close (fd);
	return (map);
}

/*static int fdf_rdline_map(char *line, t_pnt **map, int x)
{
	int		y;
	char	**split;

	y = 0;
	split = ft_split(line, ' ');
	if (!split)
		return (-1);
	while (split[y])
	{
		fdf_
	}
}*/
