/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listmanip1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:04:13 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/02/17 10:48:54 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_lstsize(t_list *lst)
{
	int	sizelst;

	sizelst = 1;
	if (!lst)
		return (0);
	while (lst->next)
	{
		sizelst++;
		lst = lst->next;
	}
	return (sizelst);
}

t_list	*ft_lstnew2(void *content)
{
	t_list	*list;

	list = malloc(sizeof(*list));
	if (!list)
		return (NULL);
	list->content = content;
	list->nbr = ft_atoi(content);
	list->next = NULL;
	return (list);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}


t_list	*fill_list(int nbn, char **nb)
{
	t_list	*stackA;
	t_list	*new;

	stackA = ft_lstnew(nb[nbn]);
	nbn--;
	while(nb > 0)
	{
		new = ft_lstnew(nb[nbn]);
		ft_lstadd_front(&stackA, new);
		nbn--;
	}
	return (stackA);
}
