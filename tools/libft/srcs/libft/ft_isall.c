/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thiagofirmino2001@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 00:52:29 by thfirmin          #+#    #+#             */
/*   Updated: 2022/12/11 21:03:27 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Iterate a string verifyng if he's fully a type string
char	*ft_isall(char *str, int (*is)(int))
{
	while (*str)
	{
		if (!is(*str))
			return (str);
		str ++;
	}
	return (0);
}
