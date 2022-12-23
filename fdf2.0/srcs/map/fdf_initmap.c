/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_initmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:00:45 by thfirmin          #+#    #+#             */
/*   Updated: 2022/12/23 18:14:08 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Verify existent and readable map, read that and build points stack
int	fdf_initmap(char *pathmap)
{
	t_pnt	*point;
	char	*line;
	int	fd;
	int	clmn;
	int lstx;

	fd = open(pathmap, O_RDONLY);
	if ((fd < 0) || (read(0, 0, fd) < 0))
		return (0);
	point = 0;
	line = 1;
	clmn = 0;
	while (line && ++clmn)
	{
		line = get_next_line(fd);
		lstx = fdf_readpnt_content(line, clmn, &point);

		free (line);
	}
	close (fd);
	return (point);
}

// Iterate points of a line and build nodes of them
// implement ft_pntadd_back
// implement ft_atoi_base
static void	fdf_readpnt_content(char *line, int y, t_pnt **pnt)
{
	char	**singpnt;
	char	*is_clrd;
	int		i;
	int		vlue[2];

	singpnt = ft_split(line, ' ');
	if (!singpnt)
		return (-1);
	i = -1;
	while (*(singpnt + ++i))
	{
		vlue[0] = ft_atoi(*(singpnt + i));
		is_clrd = ft_strchr(*(singpnt + i), ',');
		if (is_clrd)
			vlue[1] = ft_atoi_base((is_clrd + 1),);
		else
			vlue[1] = ft_atoi_base("0xFFFFFF",);
		ft_pntadd_back(pnt, ft_pntnew(vlue[0], (i + 1), y, vlue[1]));
		free (*(singpnt + i));
	}
	free (singpnt);
	return (i);
}
