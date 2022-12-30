/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 05:25:23 by thfirmin          #+#    #+#             */
/*   Updated: 2022/12/11 17:26:28 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	register int		i;
	char				*str;

	if (!s1)
		return (0);
	str = malloc(ft_strlen(s1) + 1);
	if (!str)
		return (0);
	i = -1;
	while (*(s1 + ++i))
		*(str + i) = *(s1 + i);
	*(str + i) = '\0';
	return (str);
}
