/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_putpxl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:13:11 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/11 21:49:01 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_putpxl(t_set set, int x, int y, unsigned int color)
{
	char	*begin;

	begin = set.head + (y * set.llen + x * (set.bpp / 8));
	*(unsigned int *)begin = color;
}
