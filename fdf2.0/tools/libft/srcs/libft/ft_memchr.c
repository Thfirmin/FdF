/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 20:15:37 by thfirmin          #+#    #+#             */
/*   Updated: 2022/06/22 17:22:28 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//locate byte in byte string

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n --)
	{
		if (*(char *) s == (char) c)
			return ((void *) s);
		s++;
	}
	return (0);
}
