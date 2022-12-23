/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 20:41:57 by thfirmin          #+#    #+#             */
/*   Updated: 2022/05/27 05:11:55 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//locate last occurrence of character in string

char	*ft_strrchr(const char *s, int c)
{
	int	count;
	int	lastocur;

	count = 0;
	lastocur = -1;
	while (s[count] != '\0')
	{
		if (s[count] == (char) c)
			lastocur = count;
		count ++;
	}
	if (lastocur >= 0)
		return ((char *) s + lastocur);
	else if (c == 0)
		return ((char *) s + count);
	else
		return (0);
}
