/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                       :+:     :+:            */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 05:15:38 by thfirmin          #+#    #+#             */
/*   Updated: 2022/08/15 08:55:27 by Thinotsuki   ###     ###.br              */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"

int		ft_printf(const char *ptstr, ...);
size_t	ft_putunbr_fd(unsigned int nb, int fd);
size_t	ft_putptr_fd(void *ptr, int fd);
size_t	ft_puthex_fd(unsigned int nb, char plcholder, int fd);

#endif
