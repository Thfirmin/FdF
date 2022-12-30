/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:05:20 by thfirmin          #+#    #+#             */
/*   Updated: 2022/12/20 19:17:08 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*node;
	t_list	*tmp;
	void	*elem;

	tmp = lst;
	newlst = (void *)0;
	while (tmp)
	{
		if (f)
			elem = f(tmp->content);
		node = ft_lstnew(elem);
		if (!node)
		{
			ft_lstclear(&newlst, del);
			return (0);
		}
		ft_lstadd_back(&newlst, node);
		tmp = tmp->next;
	}
	return (newlst);
}
