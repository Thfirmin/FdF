/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 20:21:05 by thfirmin          #+#    #+#             */
/*   Updated: 2022/06/08 04:30:42 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//move byte string

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*buffer;

	if (!dst && !src)
		return (0);
	buffer = dst;
	if (buffer < src)
	{
		while (len --)
			*(char *) buffer ++ = *(char *) src ++;
	}
	else
	{
		buffer += (len - 1);
		src += (len - 1);
		while (len --)
			*(char *)buffer-- = *(char *)src--;
	}
	return (dst);
}
