/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_analysis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 23:53:33 by thfirmin          #+#    #+#             */
/*   Updated: 2022/09/25 04:32:05 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*static void	fdf_linecmp(int llen);

static int	fdf_lineiter(t_point **pntmap, char **line, int y);

t_point	*fdf_map_analysis(int fd)
{
	t_point	*pntmap;
	int	y;
	int x;

	pntmap = (void *)0;
	y = 0;
	x = 1;
	while (x >= 0)
	{
		x = fdf_lineiter(&pntmap, fdf_getting_splited(fd), y);
		if (x >= 0)
			fdf_linecmp(x);
		y ++;
	}
	return (pntmap);
}

static int	fdf_lineiter(t_point **pntmap, char **line, int y)
{
	int	x;

	if (!line)
		return (-1);
	x = 0;
	while(*(line + x))
	{
		fdf_pntappend(pntmap, x, y, *(line + x));
		x ++;
	}
	fdf_free_split(line);
	return (x);
}

static void	fdf_linecmp(int llen)
{
	static int	stdlen;

	if (!stdlen)
		stdlen = llen;
	if (stdlen != llen)
		maphole_error();
}*/
static int	fdf_getzclr(char *z_clr, int logic);

static void	fdf_llength_cmp(int llength);

static int	fdf_iterline(t_point **pnt, int y, int fd);

// Analysis, validate and mount point of map
t_point	*fdf_map_analysis(int fd)
{
	int		x;
	int		y;
	t_point	*pnt;
	
	x = 0;
	y = 0;
	pnt = (void *)0;
	while (x >= 0)
	{
		x = fdf_iterline(&pnt, y, fd);
		fdf_llength_cmp(x);
		y ++;
	}
	return (pnt);
}

// 
static int	fdf_iterline(t_point **pnt, int y, int fd)
{
	char	**line;
	t_point	*newpnt;
	int		x;
	int		zclr[2];

	x = 0;
	line = fdf_getting_splited(fd);
	if (line)
	{
		while (*(line + x))
		{
			zclr[0] = fdf_getzclr(*(line + x), 1);
			zclr[1] = fdf_getzclr(*(line + x), 0);
			newpnt = fdf_pntnew(x, y, zclr[0], zclr[1]);
			fdf_pntadd_back(pnt, newpnt);
			x ++;
		}
		fdf_free_split(line);
	}
	else
		x = -1;
	return (x);
}

//
static void	fdf_llength_cmp(int llength)
{
	static int	button;
	static int	stdlen;

	if ((llength >= 0) && (!button))
	{
		stdlen = llength;
		button = 1;
	}
	if (llength >= 0)
		if (llength != stdlen)
			wrong_llength();
}

//
static int	fdf_getzclr(char *z_clr, int logic)
{
	static int	len;
	int			start;
	char		*nbr;
	int			zclr;

	if (logic)
		start = 0;
	else
		start = len;
	len = 0;
	while ((*((z_clr + start) + len) != ',') && (*((z_clr + start) + len)))
		len ++;
	nbr = ft_substr(z_clr, start, len);
	if (!nbr)
		return (0);
	zclr = fdf_getnbr(nbr);
	free (nbr);
	if (*(z_clr + len) == ',')
		len ++;
	return (zclr);
}
