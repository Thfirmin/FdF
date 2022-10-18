/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 22:17:34 by thfirmin          #+#    #+#             */
/*   Updated: 2022/10/17 22:25:25 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_perror(char *error, int fd_errno)
{
	errno = fd_errno;
	ft_putstr_fd("\e[31m", 2);
	perror (error);
	ft_putstr_fd("\e[m", 2);
	exit (2);
}
