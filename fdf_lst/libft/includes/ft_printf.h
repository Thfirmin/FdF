/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 05:15:38 by thfirmin          #+#    #+#             */
/*   Updated: 2022/10/14 21:44:35 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>

int		ft_printf(const char *ptstr, ...);
size_t	ft_ftputchr(char c);
size_t	ft_ftputstr(char *str);
size_t	ft_ftputnbr(int nb);
size_t	ft_ftputunbr(unsigned int nb);
size_t	ft_ftputptr(void *ptr);
size_t	ft_ftputhex(unsigned int nb, char plcholder);

#endif
