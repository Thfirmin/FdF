/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 23:47:20 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/17 16:32:38 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Return number of algorism in a integer
int	ft_nbrlen(int n)
{
	unsigned int	nbr;
	int				len;

	len = 0;
	if (n < 0 && ++len)
		nbr = -n;
	else
		nbr = n;
	if (nbr >= 10)
		len += ft_nbrlen(nbr / 10);
	len ++;
	return (len);
}
