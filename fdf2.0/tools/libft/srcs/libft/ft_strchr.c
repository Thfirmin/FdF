/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 20:25:02 by thfirmin          #+#    #+#             */
/*   Updated: 2022/05/27 05:10:59 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//locate first occurrence of character in string

char	*ft_strchr(const char *s, int c)
{
	int	count;

	if (!s)
		return (0);
	count = 0;
	while (s[count])
	{
		if (s[count] == (char) c)
			return ((char *) s + count);
		count ++;
	}
	if (c == 0)
		return ((char *) s + count);
	else
		return (0);
}
