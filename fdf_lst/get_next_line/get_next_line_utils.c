/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 06:25:50 by thfirmin          #+#    #+#             */
/*   Updated: 2022/10/15 09:03:02 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_ftstrchr(char *str, int c)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == (unsigned char) c)
			return (str);
		str ++;
	}
	return (0);
}

size_t	ft_ftstrlen(char *str)
{
	size_t	len;

	len = 0;
	if (str)
		while (*(str + len))
			len ++;
	return (len);
}

t_file	*backup_line(int fd, t_file *list)
{
	while (list)
	{
		if (list -> f_fd == fd)
			return (list);
		list = list -> newfile;
	}
	return (0);
}

t_file	*addnew_list(int fd, t_file *list)
{
	t_file	*new ;

	new = (t_file *) malloc (sizeof(t_file));
	if (!new)
		return (0);
	new -> f_fd = fd;
	new -> f_str = malloc(1);
	*(new -> f_str) = '\0';
	new -> newfile = 0;
	if (!list)
		list = new;
	else
	{
		while (list -> newfile)
			list = list -> newfile;
		list -> newfile = new;
	}
	return (new);
}

t_file	*ft_free(t_file *list, t_file *node)
{
	t_file	*aux;

	aux = list;
	if (node == list)
		list = node -> newfile;
	else
	{
		while ((aux -> newfile) != node)
			aux = aux -> newfile;
		aux -> newfile = node -> newfile;
	}
	free (node);
	return (list);
}
