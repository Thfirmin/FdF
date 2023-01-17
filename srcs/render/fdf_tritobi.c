/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_tritobi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:58:26 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/17 01:31:51 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_center_map(t_pnt *map, t_img img, t_set set);

static void	fdf_scaling(t_pnt *map, int offset);

static void	fdf_rotate_map(t_fdf *fdf, int z, double angle, double rot);

void	fdf_tritobi(t_fdf *fdf, double angle, double rot)
{
	t_pnt	*map;

	map = fdf->map;
	angle *= M_PI / 180;
	rot *= M_PI / 180;
	fdf_rotate_map(fdf, fdf->set.scale_z, angle, rot);
	fdf_scaling(map, fdf->set.offset);
	fdf_center_map(map, fdf->img, fdf->set);
}

static void	fdf_rotate_map(t_fdf *fdf, int z, double angle, double rot)
{
	t_pnt *map;

	map = fdf->map;
	while (map)
	{
		map->p_x = ((map->idx *  cos(angle)) + (map->idy *  (cos(angle) + cos(rot))) + (map->hgh * z * (cos(angle) - cos(rot))));
		map->p_y = ((map->idx *  sin(angle)) + (map->idy *  (sin(angle) + sin(rot))) + (map->hgh * z * (sin(angle) - sin(rot))));
		map = map->next;
	}
}

static void	fdf_scaling(t_pnt *map, int offset)
{
	while (map)
	{
		map->p_x *= offset;
		map->p_y *= offset;
		map = map->next;
	}
}

static void	fdf_center_map(t_pnt *map, t_img img, t_set set)
{
	t_pnt	*lst;
	t_pnt	*ptr;
	int	l_x;
	int	l_y;

	lst = fdf_pntlast(map);
	ptr = map;
	while ((map->idx != (lst->idx / 2)) && (map->idy != (lst->idy / 2)))
		map = map->next;
	l_x = ((img.is_x / 2) - map->p_x);
	l_y = ((img.is_y / 2) - map->p_y);
	while (ptr)
	{
		ptr->p_x = (ptr->p_x + l_x + set.mv_x);
		ptr->p_y = (ptr->p_y + l_y + set.mv_y);
		ptr = ptr->next;
	}
}
