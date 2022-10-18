/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 20:36:45 by thfirmin          #+#    #+#             */
/*   Updated: 2022/08/06 03:12:50 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//locate a substring in a n lenght string

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	while ((i <= len) && (*haystack))
	{
		if (*(needle + i) == '\0')
			return ((char *)haystack);
		else if (*(haystack + i) == *(needle + i))
			i ++;
		else if (*(haystack + i) != *(needle + i))
		{
			i = 0;
			haystack ++;
			len --;
		}
	}
	return (0);
}
