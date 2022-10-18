/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_config_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 22:34:53 by thfirmin          #+#    #+#             */
/*   Updated: 2022/10/17 23:22:56 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_config	*fdf_cnfgnew(t_point *point, t_graph *graph)
{
	t_config	*newcnfg;

	newcnfg = malloc(sizeof(t_config));
	if (!newcnfg)
		return (0);
	newcnfg->c_pnts = point;
	newcnfg->c_grph = graph;
	return (newcnfg);
}

void	fdf_cnfgclear(t_config *config)
{
	if (!config)
		return ;
	fdf_pntsclear(&config->c_pnts);
	fdf_grphclear(config->c_grph);
	free (config);
	config = 0;
}
