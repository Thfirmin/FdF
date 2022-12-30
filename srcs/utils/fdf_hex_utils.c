/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hex_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:46:00 by thfirmin          #+#    #+#             */
/*   Updated: 2022/12/27 23:30:04 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void fdf_upping(unsigned int idx, char *hex);

int	fdf_ishex(char *hex)
{
	int	i;

	if (!hex)
		return (0);
	if ((*hex == '0') && ((*(hex + 1) == 'X') || (*(hex + 1) == 'x')))
		hex += 2;
	else
		return (0);
	ft_striteri(hex, fdf_upping);
	i = -1;
	while (*(hex + ++i))
	{
		if ((*(hex + i) >= '0') && (*(hex + i) <= '9'))
			continue;
		else if ((*(hex + i) >= 'A') && (*(hex + i) <= 'F'))
			continue;
		else
			return (0);
	}
	return (1);
}

unsigned int	fdf_htoi(char *hex)
{
	int					len;
	int					base;
	unsigned int		nbr;

	ft_striteri(hex, fdf_upping);
	hex += 2;
	len = ft_strlen(hex);
	if (len > 8)
		len = 8;
	base = (len - 1);
	nbr = 0;
	while (--len > -1)
	{
		if ((*(hex + len) >= '0') && (*(hex + len) <= '9'))
			nbr += (pow(16, (base - len)) * (*(hex + len) - '0'));
		else if ((*(hex + len) >= 'A') && (*(hex + len) <= 'F'))
			nbr += (pow(16, (base - len)) * (10 + (*(hex + len) - 'A')));
	}
	return (nbr);
}

static void fdf_upping(unsigned int idx, char *hex)
{
	(void) idx;
	*hex = ft_toupper(*hex);
}

