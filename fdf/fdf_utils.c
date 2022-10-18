/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 02:38:40 by thfirmin          #+#    #+#             */
/*   Updated: 2022/09/25 04:49:39 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_getnbr(char *nbr)
{
	if (ft_strnstr(nbr, "0x", 2))
		return (fdf_todec((nbr + 2), 16));
	else
		return (fdf_todec(nbr, 10));
}


int	fdf_todec(char *nbr, int base)
{
	int	len;
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	len = ft_strlen(nbr);
	while (i < len)
	{
		if ((*(nbr + i) >= '0') && (*(nbr + i) <= '9'))
			ret += ((nbr[i] - '0') * pow(base, ((len - 1) - i)));
		else if ((nbr[i] >= 'A') && (nbr[i] <= 'Z'))
			ret += (((nbr[i] + 10) - 'A') * pow(base, ((len - 1) - i)));
		i ++;
	}
	return (ret);
}


void	fdf_free_split(char **split)
{
	int	i;

	i = 0;
	while (*(split + i))
		i ++;
	while (i--)
		free (*(split + i));
	free (split);
}

char	**fdf_getting_splited(int fd)
{
	char	*line;
	char	*bl;
	char	**splitted;

	splitted = (void *)0;
	line = get_next_line(fd);
	bl = 0;
	if (line)
	{
		bl = ft_strchr(line, '\n');
		if (bl)
			*bl = '\0';
		splitted = ft_split(line, ' ');
		free (line);
	}
	return (splitted);
}

char	*fdf_take_zclr_arg(char *zclr, int base, int *start)
{
	int	len;
	char *arg;

	len = 0;
	if (base != 16)
		while (ft_strchr("0123456789", *((zclr + *start) + len)))
			len++;
	else
	{
		*start += 2;
		while (ft_strchr("0123456789ABCDEF", *((zclr + *start) + len)))
			len ++;
	}
	arg = ft_substr(zclr, *start, len);
	*start += len;
	return (arg);
}
