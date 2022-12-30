/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 19:45:36 by thfirmin          #+#    #+#             */
/*   Updated: 2022/12/28 19:36:26 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_UTILS_H
# define FDF_UTILS
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>
# include "libft.h"

void			fdf_error(char *fdf_errno, t_fdf **fdf);
int				fdf_ishex(char *hex);
unsigned int	fdf_htoi(char *hex);
int				fdf_isnumber(char *nbr);
void			fdf_closefile(int fd, char *line);

#endif