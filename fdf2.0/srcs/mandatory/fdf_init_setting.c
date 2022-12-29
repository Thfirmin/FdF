/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init_setting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 23:46:37 by thfirmin          #+#    #+#             */
/*   Updated: 2022/12/28 19:29:39 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_init_setting(char *pathmap, t_fdf **fdf)
{
	*fdf = ft_calloc(1, sizeof(t_fdf));
	if (!*fdf)
		fdf_error(strerror(ENOMEM), 0);
	fdf_std_settings(fdf);
	fdf_initmap(pathmap, fdf);
}

// Define Standard settings of fdf
void	fdf_std_settings(t_fdf **fdf)
{
	t_config	*conf;

	(**fdf).cnfg = ft_calloc(1, sizeof(t_config));
	if (!(**fdf).cnfg)
		fdf_error(strerror(ENOMEM), fdf);
	conf = (**fdf).cnfg;
	conf->std_color = 0xFFFFFF;
}
