/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 23:10:31 by thfirmin          #+#    #+#             */
/*   Updated: 2022/09/24 23:16:56 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	invalid_argument(void)
{
	errno = EINVAL;
	perror("Usage : ./fdf <filename> [ case_size z_size ]");
	exit (1);
}

void	file_not_found(char *file)
{
	ft_putstr_fd("No file ", 1);
	perror (file);
	exit (1);
}

void	wrong_llength(void)
{
	perror ("Found wrong line length. Exiting.");
	exit (1);
}

