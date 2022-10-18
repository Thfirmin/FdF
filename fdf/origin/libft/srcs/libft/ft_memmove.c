/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 20:21:05 by thfirmin          #+#    #+#             */
/*   Updated: 2022/08/06 02:37:31 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//move byte string

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;

	if (!dst && !src)
		return (0);
	i = 0;
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
	{
		i += (len - 1);
		src += (len - 1);
		while (len --)
			*(char *)(dst + i--) = *(char *)src--;
	}
	return (dst);
}
