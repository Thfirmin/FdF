/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:25:32 by thfirmin          #+#    #+#             */
/*   Updated: 2022/12/11 17:30:46 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	count;

	count = ft_strlen(s);
	if (start > count)
		start = count;
	s += start;
	count = ft_strlen(s);
	if (len > count)
		len = count;
	str = malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, s, len + 1);
	return (str);
}
