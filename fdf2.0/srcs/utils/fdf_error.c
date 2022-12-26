/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 20:03:58 by thfirmin          #+#    #+#             */
/*   Updated: 2022/12/26 01:15:58 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_error(char *fdf_errno)
{
	ft_putendl_fd(fdf_errno, 2);
	exit(2);
}

void	fdf_read_error(char *line, char **split, int fd, char *fdf_errno)
{
	while(1)
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	if (split)
		ft_frsplit(split);
	if (fd >= 0)
		close (fd);
	fdf_error(fdf_errno);
}
