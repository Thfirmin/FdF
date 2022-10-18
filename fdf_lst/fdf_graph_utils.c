/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_graph_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 23:08:03 by thfirmin          #+#    #+#             */
/*   Updated: 2022/10/17 23:21:56 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_graph	*fdf_grphnew(int x, int y, void *nmlx, void *nwin)
{
	t_graph	*newgrph;

	newgrph = malloc(sizeof(t_graph));
	if (!newgrph)
		return (0);
	newgrph->win_x = x;
	newgrph->win_y = y;
	newgrph->mlx = nmlx;
	newgrph->win = nwin;
	return (newgrph);
}

void	fdf_grphclear(t_graph *graph)
{
	if (!graph)
		return ;
	free (graph);
	graph = 0;
}
