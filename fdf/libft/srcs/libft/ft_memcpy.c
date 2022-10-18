/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                       :+:     :+:            */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 20:19:34 by thfirmin          #+#    #+#             */
/*   Updated: 2022/08/23 03:50:04 by Thinotsuki   ###     ###.br              */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//copy byte string

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int	i;

	if (!dst && !src)
		return (0);
	i = 0;
	while (n --)
	{	
		*(char *)(dst + i++) = *(char *) src++;
	}
	return (dst);
}
