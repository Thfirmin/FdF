/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                             :+:     :+:            */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 06:25:50 by thfirmin          #+#    #+#             */
/*   Updated: 2022/09/13 06:51:08 by Thinotsuki   ###     ###.br              */
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

t_list	*backup_line(int fd, t_list *list)
{
	while (list)
	{
		if (list -> f_fd == fd)
			return (list);
		list = list -> newfile;
	}
	return (0);
}

t_list	*addnew_list(int fd, t_list *list)
{
	t_list	*new ;

	new = (t_list *) malloc (sizeof(t_list));
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

t_list	*ft_free(t_list *list, t_list *node)
{
	t_list	*aux;

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
