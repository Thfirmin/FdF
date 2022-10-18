/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 23:47:20 by thfirmin          #+#    #+#             */
/*   Updated: 2022/08/06 23:51:30 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbrlen(ssize_t n)
{
	size_t	nbr;
	int		len;

	len = 0;
	if (n < 0)
	{
		len += 1;
		nbr = (n * -1);
	}
	else
		nbr = n;
	if (nbr != 0)
	{
		len += ft_nbrlen(nbr / 10);
		len ++;
	}
	return (len);
}
