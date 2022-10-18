/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                      :+:     :+:            */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 00:06:44 by thfirmin          #+#    #+#             */
/*   Updated: 2022/08/23 03:51:15 by Thinotsuki   ###     ###.br              */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	size_t	len;
	char	*str;

	start = 0;
	while (ft_strchr(set, s1[start]))
		start ++;
	len = (ft_strlen(s1) - 1);
	while (ft_strchr(set, s1[len]))
		len --;
	str = ft_substr(s1, start, ((len - start) + 1));
	return (str);
}
