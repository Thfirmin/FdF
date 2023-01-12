/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_equations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:16:10 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/11 16:50:51 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//u = cos(a) + ycos(a+120°) + zcos(a-120°)
//v = xsin(a) + ysin(a+120°) + zsin(a-120°)

//	degtorad()
void	fdf_trdtoiso(t_pnt *map, long double angle, long double rot)
{
	angle *= M_PI / 180;
	rot *= M_PI / 180;
	while (map)
	{
		map->p_x = ((map->p_x * cos(angle)) + (map->p_y * (cos(angle) + cos(rot))) + (map->hgh * (cos(angle) - cos(rot))));
		map->p_y = ((map->p_x * sin(angle)) + (map->p_y * (sin(angle) + sin(rot))) + (map->hgh * (sin(angle) - sin(rot))));
		map = map->next;
	}
}
