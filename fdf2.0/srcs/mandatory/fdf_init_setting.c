/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init_setting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 23:46:37 by thfirmin          #+#    #+#             */
/*   Updated: 2022/12/28 00:13:26 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*fdf_init_setting(char *pathmap)
{
	t_fdf	*fdf;

	fdf = ft_calloc(1, sizeof(t_fdf));
	if (!fdf)
		return (0);
	fdf_std_settings(fdf);
	fdf_initmap(pathmap, fdf);
	return (fdf);
}

// Define Standard settings of fdf
void	fdf_std_settings(t_fdf *fdf)
{
	t_config	*conf;

	conf = ft_calloc(1, sizeof(t_config));
	if (!conf)
		return ;
	fdf->cnfg = conf;
	conf->std_color = 0xFFFFFF;
}
