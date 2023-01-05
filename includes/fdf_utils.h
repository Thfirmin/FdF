/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 19:45:36 by thfirmin          #+#    #+#             */
/*   Updated: 2023/01/03 22:37:32 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_UTILS_H
# define FDF_UTILS

// Fdf Exit
int				fdf_cross(t_fdf *fdf);
void			fdf_error(char *fdf_errno, t_fdf *fdf);

// Nbr Utils
int				fdf_ishex(char *hex);
unsigned int	fdf_htoi(char *hex);
int				fdf_isnumber(char *nbr);

// File Utils
void			fdf_closefile(int fd, char *line);

// Draw Utils
void			fdf_putpxl(t_set set, int x, int y, int color);

// Key Handler
int				fdf_keyhandler(int key, t_fdf *fdf);

#endif
