/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                       :+:     :+:            */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 23:58:21 by thfirmin          #+#    #+#             */
/*   Updated: 2022/09/01 01:19:39 by Thinotsuki   ###     ###.br              */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	holderfinder(const char plcholder, va_list plcvalue);

int	ft_printf(const char *ptstr, ...)
{
	size_t	i;
	size_t	len;
	va_list	plcvalue;

	i = 0;
	len = 0;
	if (!ptstr)
		return (0);
	va_start(plcvalue, ptstr);
	while (ptstr[i])
	{
		if (ptstr[i] == '%' && ft_strchr("cspdiuxX%", ptstr[i + 1]))
		{
			len += holderfinder(ptstr[i + 1], plcvalue);
			i += 2;
		}
		else
		{
			if (ptstr[i] == '%')
				i++;
			len += ft_putchar_fd(ptstr[i++], 1);
		}
	}
	va_end(plcvalue);
	return (len);
}

static size_t	holderfinder(const char plcholder, va_list plcvalue)
{
	size_t	len;
	char	*str;

	len = 0;
	if (plcholder == '%')
		len += ft_putchar_fd('%', 1);
	else if (plcholder == 'c')
		len += ft_putchar_fd(va_arg(plcvalue, int), 1);
	else if (plcholder == 's')
	{
		str = va_arg(plcvalue, char*);
		if (str)
			len += ft_putstr_fd(str, 1);
		else
			len += ft_putstr_fd("(null)", 1);
	}
	else if (plcholder == 'd' || plcholder == 'i')
		len += ft_putnbr_fd(va_arg(plcvalue, int), 1);
	else if (plcholder == 'u')
		len += ft_putunbr_fd(va_arg(plcvalue, unsigned int), 1);
	else if (plcholder == 'p')
		len += ft_putptr_fd(va_arg(plcvalue, void *), 1);
	else if (plcholder == 'x' || plcholder == 'X')
		len += ft_puthex_fd(va_arg(plcvalue, int), plcholder, 1);
	return (len);
}
