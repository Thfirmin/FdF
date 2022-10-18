/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                        :+:     :+:            */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:37:55 by thfirmin          #+#    #+#             */
/*   Updated: 2022/08/23 03:48:24 by Thinotsuki   ###     ###.br              */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//write zeroes to a n byte string

void	ft_bzero(void *s, size_t n)
{
	if (!s)
		return ;
	while (n--)
		*(char *)s++ = 0;
}
