/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_pntnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:17:23 by thfirmin          #+#    #+#             */
/*   Updated: 2022/12/23 17:29:31 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_pnt	*fdf_pntnew(int hgh, int x, int y, int clr)
{
	t_pnt	*newpnt;

	newpnt = ft_calloc(sizeof(t_pnt));
	if (!newpnt)
		return (0);
	(*newpnt).hgh = hgh;
	(*newpnt).p_x = x;
	(*newpnt).p_y = y;
	(*newpnt).clr = clr;
	(*newpnt).next = (void *)0;
	return (newpnt);
}

void	**fdf_pntclear(t_pnt **pnt)
{
	t_pnt	*nxt;

	while (*pnt)
	{
		nxt = (**pnt).next;
		free(*pnt);
		*pnt = nxt;
	}
}
