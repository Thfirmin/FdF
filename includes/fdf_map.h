/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 01:56:31 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/13 02:13:14 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_MAP_H
# define FDF_MAP_H

void	fdf_init_map(t_fdf *fdf, char *pathmap);
t_pnt	*fdf_pntnew(int hgh, int x, int y, unsigned int clr);
void	fdf_pntadd_back(t_pnt **map, t_pnt *point);
t_pnt	*fdf_pntlast(t_pnt *map);
void	fdf_pntclear(t_pnt **map);

#endif
