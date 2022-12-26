/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 19:45:36 by thfirmin          #+#    #+#             */
/*   Updated: 2022/12/26 01:16:14 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_UTILS_H
# define FDF_UTILS
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include "libft.h"

void	fdf_error(char *fdf_errno);
void	fdf_read_error(char *line, char **split, int fd, char *fdf_errno);

#endif
