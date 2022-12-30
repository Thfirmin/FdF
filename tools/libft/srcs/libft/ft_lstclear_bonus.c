/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:58:13 by thfirmin          #+#    #+#             */
/*   Updated: 2022/12/20 19:16:43 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Clear propely a full list
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nxt;

	while (*lst)
	{
		nxt = (**lst).next;
		if (del)
			del((**lst).content);
		free (*lst);
		*lst = nxt;
	}
}
