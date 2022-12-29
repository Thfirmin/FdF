/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 20:03:58 by thfirmin          #+#    #+#             */
/*   Updated: 2022/12/29 14:16:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_error(char *fdf_errno, t_fdf **fdf)
{
	if (fdf)
		fdf_fdfclear(fdf);
	ft_putendl_fd(fdf_errno, 2);
	exit(2);
}
