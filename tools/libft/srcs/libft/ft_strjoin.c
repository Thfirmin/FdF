/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 23:22:34 by thfirmin          #+#    #+#             */
/*   Updated: 2022/06/14 21:16:55 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		len;

	len = (ft_strlen(s1) + ft_strlen(s2));
	newstr = malloc((len + 1) * sizeof(char));
	if (!newstr)
		return ((void *)0);
	while (s1 && *s1)
		*newstr++ = *s1++;
	while (s2 && *s2)
		*newstr++ = *s2++;
	*newstr = '\0';
	return (newstr - len);
}
