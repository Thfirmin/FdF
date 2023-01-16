/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_putpxl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 23:05:12 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/15 21:19:43 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_putpxl(t_img img, int x, int y, unsigned int color)
{
	char	*begin;

	if (x < 0 || x > (img.is_x - 1))
		return ;
	if (y < 0 || y > (img.is_y - 1))
		return ;
	begin = img.head + (y * img.llen + x * (img.bpp / 8));
	*(unsigned int *)begin = color;
}
