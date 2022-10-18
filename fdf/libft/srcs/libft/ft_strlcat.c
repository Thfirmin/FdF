/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 20:26:01 by thfirmin          #+#    #+#             */
/*   Updated: 2022/08/06 02:53:16 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//size-bounded string concatenation

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	t_size;

	t_size = ft_strlen(src);
	while (*dst != '\0' && dstsize > 0)
	{
		t_size ++;
		dst ++;
		dstsize --;
	}
	while (dstsize > 1 && *src)
	{
		*dst++ = *src++;
		dstsize --;
	}
	if (dstsize)
		*dst = '\0';
	return (t_size);
}
