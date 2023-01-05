/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 20:03:58 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/03 22:36:45 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_error(char *fdf_errno, t_fdf *fdf)
{
	if (fdf)
		fdf_fdfclear(fdf);
	ft_putendl_fd(fdf_errno, 2);
	exit(2);
}

int	fdf_cross(t_fdf *fdf)
{
	fdf_fdfclear(fdf);
	exit (0);
}
