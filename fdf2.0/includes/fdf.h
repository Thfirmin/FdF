/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:18:24 by thfirmin          #+#    #+#             */
/*   Updated: 2022/12/26 00:33:37 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "get_next_line.h"
# include "fdf_data.h"
# include "fdf_utils.h"
# include <fcntl.h>

// Map init
void	fdf_is_validmap(char *pathmap);
t_pnt	*fdf_initmap(char *pathmap);

#endif
