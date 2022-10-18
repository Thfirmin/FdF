/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 01:11:07 by thfirmin          #+#    #+#             */
/*   Updated: 2022/10/18 02:15:59 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	fdf_htoi(char *nbr);

static void	fdf_iterpnt(t_point **pnt, int x, int y, char *arg);

static void	fdf_llen_cmp(int x);

static int	fdf_iterline(t_point **pnt, int fd, int y);

t_point	*fdf_read_map(char *argv[])
{
	int	fd;
	int x
	int	y;
	t_point	*pnts;

	fd = open(argv[1], O_RDONLY);
	if ((read(fd, 0, 0)) < 0)
		fdf_perror("Error", 2);
	pnt = (void *)0;
	y = 0;
	x = 0;
	while (x >= 0)
	{
		x = fdf_iterline(&pnt, fd, y);
		fdf_llen_cmp(x);
		y ++;
	}
}

static int	fdf_iterline(t_point **pnt, int fd, int y)
{
	int		x;
	char	*line;
	char	**args;
	char	*bl;

	x = 0;
	line = get_next_line(fd);
	if (line)
	{
		bl = ft_strchr(line, '\n');
		if (bl)
			*bl = '\0';
		args = ft_split(line, ' ');
		free (line);
		while (args[x])
		{
			fdf_iterpnt(pnt, x, y, args[x]);
			free(args[x]);
			x ++;
		}
		free(args);
	}
	else
		x = -1;
	return (x);
}

static void	fdf_llen_cmp(int x)
{
	...;
}

static void	fdf_iterpnt(t_point **pnt, int x, int y, char *arg)
{
	char	**sarg;
	int		clr;
	int		z;
	int		i;

	sarg = ft_split(arg, ',');
	z = ft_atoi(sarg[0]);
	if (sarg[1])
		clr = fdf_htoi(sarg[1]);
	i = 0;
	while (sarg[i])
		free (sarg[i++]);
	free (sarg);
	fdf_pntsadd_back(pnt, fdf_pntsnew(x, y, z, clr));
}

static int	fdf_htoi(char *nbr)
{
	int	num;
	int signal;
	int	i;

	if (*nbr == '-')
	{
		signal = -1;
		nbr ++;
	}
	if (ft_strncmp(nbr, "0x", 2))
		return (0);
	nbr += 2;
	i = (ft_strlen(nbr) - 1);
	while (i)

}
