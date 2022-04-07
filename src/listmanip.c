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

t_list	*ft_lstnew2(char *src)
{
	t_list	*list;

	list = malloc(sizeof(*list));
	if (!list)
		return (NULL);
	list->src = src;
	list->nbr = ft_atoistrong(src);
	list->next = NULL;
	return (list);
}

t_list	*ft_lstnbnew(int avg)
{
	t_list	*list;

	list = malloc(sizeof(*list));
	if (!list)
		return (NULL);
	list->nbr = avg;
	list->next = NULL;
	return (list);
}

void	lst_del(t_list **stack)
{
	while ((*stack)->next)
	{
		(*stack)->src = NULL;
		(*stack)->nbr = 0;
		free (*stack);
		*stack = (*stack)->next;
	}
}