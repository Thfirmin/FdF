/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keyhandler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 22:34:55 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/05 00:15:18 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_change_spc(int key, t_fdf *fdf)
{
	if (key == 108)
		fdf->set.p_spc ++;
	else
		fdf->set.p_spc --;
}

int	fdf_keyhandler(int key, t_fdf *fdf)
{
	if (key == E_ESC)
		fdf_cross(fdf);
	else if ((key == 104) || (key == 108))
		fdf_change_spc(key, fdf);
	return (0);
}