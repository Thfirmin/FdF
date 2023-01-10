/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:18:24 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/10 00:46:05 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "fdf_libs.h"
# include "fdf_data.h"
# include "fdf_utils.h"

// Main functions
void	fdf_is_validmap(char *pathmap);
void	fdf_init(char *pathmap, t_fdf *fdf);
void	fdf_sethook(t_fdf *fdf);
int		fdf_printfdf(t_fdf *fdf);

// Utils
void	fdf_initmap(char *pathmap, t_fdf *fdf);
void	fdf_putpxl(t_set set, int x, int y, int color);

#endif
