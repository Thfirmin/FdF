/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 01:37:43 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/13 01:37:45 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

	void	fdf_error_handler(char	*error, t_fdf *fdf)
	{
		if (fdf)
			fdf_head_handler(fdf);
	ft_putendl_fd(error, 2);
	exit (2);
}
