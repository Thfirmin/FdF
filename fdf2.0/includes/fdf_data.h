/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_data.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:12:57 by thfirmin          #+#    #+#             */
/*   Updated: 2022/12/23 17:29:49 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_DATA_H
# define FDF_DATA_H

typedef struct s_pnt
{
	int				hgh;
	int				p_x;
	int				p_y;
	int				clr;
	struct s_pnt	*next;
}					t_pnt

// Points struct
t_pnt	*fdf_newpnt(int, hgh, int x, int y, int clr);
void	**fdf_pntclear(t_pnt **pnt);

#endif
