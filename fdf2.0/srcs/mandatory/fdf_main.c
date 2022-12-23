/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:19:46 by thfirmin          #+#    #+#             */
/*   Updated: 2022/12/23 17:30:35 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_pnt	*map;
	t_pnt	*ptr;

	if (argc != 2)
		return (2);
	map = fdf_initmap(argv[1]);
	ptr = map;
	while (map)
	{
		ft_printf ("(%d, %d): %d [%d]", map->p_x, map->p_y, map->hgh, map->clr);
		map = map->next;
	}
	fdf_pntclear(&ptr);
	return (0);
}
