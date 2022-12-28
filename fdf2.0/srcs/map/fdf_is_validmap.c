/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_is_validmap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 00:10:14 by thfirmin          #+#    #+#             */
/*   Updated: 2022/12/27 22:46:17 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Verify vlue of points
static char	*fdf_isvalid_vlue(char *line);

// Verify length of line and compare with others
static char	*fdf_isvalid_length(char *line);

// Verify inexistent or non-readable map
static int	fdf_isreadable(char *pathmap);

// Verify extension of map
static char	*fdf_isvalid_extension(char *pathmap);

// Verify inexistent/non-readable or invalid length line map
void	fdf_is_validmap(char *pathmap)
{
	int		fd;
	char	*ret;
	char	*line;

	if ((fd = fdf_isreadable(pathmap)) < 0)
		fdf_error(strerror(ENOENT));
	line = (void *)1;
	ret = fdf_isvalid_extension(pathmap);
	while (line)
	{
		line = get_next_line(fd);
		if (!ret)
			ft_bzero((void *)ft_strchr(line, '\n'), 1);
		if (!ret)
			ret = fdf_isvalid_length(line);
		if (!ret)
			ret = fdf_isvalid_vlue(line);
		free (line);
	}
	close (fd);
	if (ret)
		fdf_error(ret);
}

static char	*fdf_isvalid_extension(char *pathmap)
{
	char	*extension;

	extension = ft_strrchr(pathmap, '.');
	if (!extension)
		return ("Invalid map: extension .fdf only");
	if (!ft_strnstr(extension, ".fdf", 4))
		return ("Invalid map: extension .fdf only");
	return (0);
}

static int	fdf_isreadable(char *pathmap)
{
	int	fd;

	fd = open(pathmap, O_RDONLY);
	if (read(fd, 0, 0) < 0)
		return (-1);
	return (fd);
}

static char	*fdf_isvalid_length(char *line)
{
	char		**split;
	int			i;
	static int	len = -1;

	if (!line)
		return (0);
	split = ft_split(line, ' ');
	if (!split)
		return (strerror(ENOMEM));
	i = -1;
	while (*(split + ++i))
		if (!ft_isprint(*(*(split + i))))
			break ;
	if (len < 0)
		len = i;
	else if (len != i)
		return ("Invalid map: incorrect line length");
	return (0);
}

static char	*fdf_isvalid_vlue(char *line)
{
	char	**split;
	char	*hex;
	int		i;
	int		ret;

	if (!line)
		return (0);
	split = ft_split(line, ' ');
	if (!split)
		return (strerror(ENOMEM));
	i = -1;
	ret = 0;
	while (*(split + ++i))
	{
		hex = ft_strchr(*(split + i), ',');
		if (hex)
			*hex++ = 0;
		if (!ret && !fdf_isnumber(*(split + i)))
			ret = 1;
		if (!ret && hex && !fdf_ishex(hex))
			ret = 1;
	}
	ft_frsplit(split);
	if (ret)
		return ("Invalid map: incorrect point parameter <heigh>,<color>");
	return (0);
}

