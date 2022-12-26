/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_is_validmap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 00:10:14 by thfirmin          #+#    #+#             */
/*   Updated: 2022/12/26 13:22:03 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//static int	fdf_splititer(char **split);

// Verify inexistent or non-readable map
static int	fdf_isreadable(char *pathmap);

// Verify extension of map
static int	fdf_isvalid_extension(char *pathmap);

// Verify inexistent/non-readable or invalid length line map
void	fdf_is_validmap(char *pathmap)
{
	int		fd;
	//int		ret;
	//char	*line;
	//char	**split;

	if (!fdf_isvalid_extension(pathmap))
		fdf_error("Invalid map extension");
	if ((fd = fdf_isreadable(pathmap)) < 0)
		fdf_error(strerror(ENOENT));
	/*ret = 0;
	while (line)
	{
		line = get_next_line(fd);
		split = ft_split(line, ' ');
		if (!ret && !split)
			ret = ENOMEM;
		if (!ret && !fdf_is_validpnt(split))
			ret = -1;
		ft_frsplit(split);
	}*/
	close (fd);
}

static int	fdf_isvalid_extension(char *pathmap)
{
	char	*extension;

	extension = ft_strrchr(pathmap, '.');
	if (!extension)
		return (0);
	if (!ft_strnstr(extension, ".fdf", 4))
		return (0);
	return (1);
}

static int	fdf_isreadable(char *pathmap)
{
	int	fd;

	fd = open(pathmap, O_RDONLY);
	if (read(fd, 0, 0) < 0)
		return (-1);
	return (fd);
}

/*static int	fdf_splititer(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		if (ft_isprint(*split[i]))
			i ++;
		else
			break;
	}
	return (i);
}*/
