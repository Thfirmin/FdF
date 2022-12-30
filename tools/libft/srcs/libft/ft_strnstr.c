/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 20:36:45 by thfirmin          #+#    #+#             */
/*   Updated: 2022/06/22 16:28:01 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//locate a substring in a n lenght string

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	index;

	index = 0;
	if (*needle == '\0')
		return ((char *) haystack);
	while ((index <= len) && *haystack != '\0')
	{
		if (*(needle + index) == '\0')
			return ((char *)haystack);
		else if (*(haystack + index) == *(needle + index))
			index ++;
		else if (*(haystack + index) != *(needle + index))
		{
			index = 0;
			haystack ++;
			len --;
		}
	}
	return (0);
}
