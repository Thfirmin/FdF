/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 23:52:42 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/16 01:15:16 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "fdf_libs.h"
# include "fdf_data.h"
# include "fdf_handlers.h"
# include "fdf_map.h"
# include "fdf_render.h"

void	fdf_init(t_fdf *fdf, char *pathmap);

#endif
