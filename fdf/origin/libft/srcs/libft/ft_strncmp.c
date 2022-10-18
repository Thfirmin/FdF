/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 20:36:03 by thfirmin          #+#    #+#             */
/*   Updated: 2022/08/06 03:05:34 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//compare strings of n lenght

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;

	if (!n)
		return (0);
	count = 0;
	while (n-- && (!s1[count] || !s2[count]))
	{
		if (s1[count] != s2[count])
			break ;
		count ++;
	}
	return ((unsigned char) s1[count] - (unsigned char) s2[count]);
}
