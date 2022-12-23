/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 20:36:03 by thfirmin          #+#    #+#             */
/*   Updated: 2022/06/08 08:26:26 by thfirmin         ###   ########.fr       */
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
	while (count < (n - 1))
	{
		if (s1[count] == '\0' || s2[count] == '\0')
			break ;
		else if (s1[count] != s2[count])
			break ;
		count ++;
	}
	return ((unsigned char) s1[count] - (unsigned char) s2[count]);
}
