/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_closefile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:14:31 by thfirmin          #+#    #+#             */
/*   Updated: 2022/12/28 19:36:44 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_closefile(int fd, char *line)
{
	while (1)
	{
		if (line)
			free(line);
		else
			break;
		line = get_next_line(fd);
	}
	close (fd);
}
