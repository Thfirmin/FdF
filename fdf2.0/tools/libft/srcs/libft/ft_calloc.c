/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 05:13:14 by thfirmin          #+#    #+#             */
/*   Updated: 2022/12/30 00:16:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			total;
	register size_t	i;
	register char	*ptr;

	total = count * size;
	if ((total < count) || (total < size))
		return (0);
	ptr = malloc(total);
	if (!ptr)
		return (0);
	i = 0;
	while (i < total)
		*(ptr + i++) = 0;
	return (ptr);
}
