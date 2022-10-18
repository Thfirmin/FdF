/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                   :+:     :+:            */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 20:51:56 by thfirmin          #+#    #+#             */
/*   Updated: 2022/09/01 01:20:24 by Thinotsuki   ###     ###.br              */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putunbr_fd(unsigned int nb, int fd)
{
	size_t	len;

	len = 0;
	if (nb >= 10)
		len += ft_putunbr_fd((nb / 10), fd);
	len += ft_putchar_fd(((nb % 10) + '0'), fd);
	return (len);
}
