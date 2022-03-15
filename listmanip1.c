/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listmanip1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:04:13 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/03/11 16:31:04 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	list->nbr = ft_atoistrong(content);
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

void	lst_del(t_list **stack)
{
	while ((*stack)->next)
	{
		(*stack)->content = NULL;
		(*stack)->nbr = 0;
		free (*stack);
		*stack = (*stack)->next;
	}
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*lastel;

	if (!new)
		return ;
	lastel = ft_lstlast(*alst);
	if (!lastel)
		*alst = new;
	else
		lastel->next = new;
}
