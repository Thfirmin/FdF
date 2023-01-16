/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_handlers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 00:11:28 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/16 01:29:02 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_HANDLERS_H
# define FDF_HANDLERS_H

void	fdf_error_handler(char	*error, t_fdf *fdf);
void	fdf_head_handler(t_fdf *fdf);
void	fdf_hooks_handler(t_fdf *fdf);
void	fdf_move_map(t_fdf *fdf, int key);
void	fdf_rot_map(t_fdf *fdf, int key);
void	fdf_resize_map(t_fdf *fdf, int key);
#endif
