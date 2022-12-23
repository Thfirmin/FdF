/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 20:19:34 by thfirmin          #+#    #+#             */
/*   Updated: 2022/06/14 21:10:44 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//copy byte string

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*buffer;

	if (!dst && !src)
		return (0);
	buffer = dst;
	while (n --)
	{	
		*(char *) buffer ++ = *(char *) src++;
	}
	return (dst);
}
