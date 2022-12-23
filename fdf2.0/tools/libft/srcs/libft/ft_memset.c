/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 20:22:24 by thfirmin          #+#    #+#             */
/*   Updated: 2022/06/14 21:11:56 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//write a byte to n byte string

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*temp;

	temp = b;
	while (len--)
	{
		*temp++ = c;
	}
	return (b);
}
