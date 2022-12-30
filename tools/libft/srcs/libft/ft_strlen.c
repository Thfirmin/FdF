/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 20:35:17 by thfirmin          #+#    #+#             */
/*   Updated: 2022/05/15 10:05:21 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//find length of string

size_t	ft_strlen(const char *str)
{
	unsigned int	count;

	count = 0;
	while (str && str[count])
		count ++;
	return (count);
}
