/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:19:46 by thfirmin          #+#    #+#             */
/*   Updated: 2022/12/26 01:14:19 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_pntdiagnostic(t_pnt *map);

int	main(int argc, char *argv[])
{
	t_pnt	*map;
	if (argc != 2)
		fdf_error(strerror(EINVAL));
	fdf_is_validmap(argv[1]);
	map = fdf_initmap(argv[1]);
	fdf_pntdiagnostic(map);
	fdf_pntclear(&map);
	return (0);
}

static void	fdf_pntdiagnostic(t_pnt *map)
{
	int		i;

	i = 0;
	ft_printf("\n|------------------------| MAP |------------------------|\n");
	while (map)
	{
		ft_printf("point[%d] |heigh:%d|x:%d|y:%d|color:%d|\n",
				i++,
				map->hgh,
				map->p_x,
				map->p_y,
				map->clr
				);
		map = map->next;
	}
	ft_printf("\n|-------------------------------------------------------|\n");
}
