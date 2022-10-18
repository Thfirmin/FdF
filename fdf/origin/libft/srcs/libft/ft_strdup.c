/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 05:25:23 by thfirmin          #+#    #+#             */
/*   Updated: 2022/08/06 02:45:44 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	str = ft_calloc((ft_strlen(s1) + 1), sizeof(*s1));
	if (!str)
		return (0);
	i = 0;
	while (*s1)
		*(str + i++) = *s1++;
	*(str + i) = '\0';
	return (str);
}
