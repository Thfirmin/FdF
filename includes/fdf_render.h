/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_render.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 23:07:19 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/15 23:49:50 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_RENDER_H
# define FDF_RENDER_H

int				fdf_render_map(t_fdf *fdf);
void			fdf_putpxl(t_img img, int x, int y, unsigned int color);
void			fdf_tritobi(t_fdf *fdf, double angle, double rot);
void			fdf_putline(t_fdf *fdf, t_pnt *bgn, t_pnt *end);
unsigned int	fdf_clr(t_pnt *bgn, t_pnt *end, int dp, int bin);

#endif
