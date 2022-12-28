/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_isnumber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:25:54 by thfirmin          #+#    #+#             */
/*   Updated: 2022/12/27 21:57:38 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_isnumber(char *nbr)
{
	int	i;

	if (!nbr)
		return (0);
	if ((*nbr == '-') || (*nbr == '+'))
		nbr++;
	i = -1;
	while (*(nbr + ++i))
		if (!ft_isdigit(*(nbr + i)))
			return (0);
	return (1);
}
