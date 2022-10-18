/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 22:08:12 by thfirmin          #+#    #+#             */
/*   Updated: 2022/10/18 02:16:32 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//FDF Main
int	main(int argc, char *argv[])
{
	t_config	*conf;
	t_point		*pnt;

	if (argc != 2)
		fdf_perror("Error", 22);
	pnt	= fdf_read_map(argv);
	return (0);
}

t_point	*fdf_read_map(char *argv[])
{
	int	fd;


	fd = open(argv[1], O_RDONLY);
	if ((read(fd, 0, 0) < 0))
		fdf_perror ("Error", 2);

}
