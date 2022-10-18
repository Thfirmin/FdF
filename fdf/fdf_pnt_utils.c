/* ************************************************************************** */
/*                                                                            */
/*                                                  ::::::::::: ::::::::::    */
/*   fdf_pnt_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+     +:+             */
/*   By: Thinotsuki <thinotsukimichi@gmail.com>      +#+     :#::+::#         */
/*                                                  +#+     +#+               */
/*   Created: 2022/09/23 19:46:34 by Thinotsuki    #+#     #+#                */
/*   Updated: 2022/09/25 05:22:47 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Create a new t_point node
t_point	*fdf_pntnew(int x, int y, int z, int clr)
{
	t_point	*newpnt;

	newpnt = malloc (sizeof(t_point));
	if (!newpnt)
		return (0);
	newpnt->pt_x = x;
	newpnt->pt_y = y;
	newpnt->pt_z = z;
	newpnt->pt_clr = clr;
	newpnt->pt_next = (void *)0;
	return (newpnt);
}

// Give the last node of a t_point list
t_point	*fdf_pntlast(t_point *pnt)
{
	if (!pnt)
		return (0);
	while (pnt->pt_next)
		pnt = pnt->pt_next;
	return (pnt);
}

// Add a new node at back of a t_point list
void	fdf_pntadd_back(t_point **pnt, t_point *new)
{
	t_point	*lst_pnt;

	lst_pnt = fdf_pntlast(*pnt);
	if (lst_pnt)
		lst_pnt->pt_next = new;
	else
		*pnt = new;
}

// Clear a list of t_point nodes
void	fdf_pntclear(t_point **pnt)
{
	t_point	*nextpnt;

	if (!pnt)
		return ;
	while (*pnt)
	{
		nextpnt = (**pnt).pt_next;
		free (*pnt);
		*pnt = nextpnt;
	}
}

t_window	*fdf_winnew(void *mlx, void *win, int win_xy[2], t_point *fdf_pnt)
{
	t_window	*newwin;

	newwin = malloc (sizeof(t_window));
	if (!newwin)
		return (0);
	newwin->mlx = mlx;
	newwin->win = win;
	newwin->win_x = win_xy[0];
	newwin->win_y = win_xy[1];
	newwin->fdf_pnt = fdf_pnt;
	return (newwin);
}

