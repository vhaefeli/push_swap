/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listmanip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:04:13 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/04/20 13:44:00 by vhaefeli         ###   ########.fr       */
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
	list->position = 0;
	list->next = NULL;
	return (list);
}

void	lst_del(t_list **stack)
{
	while (*stack && (*stack)->next)
	{
		(*stack)->src = NULL;
		(*stack)->nbr = 0;
		free (*stack);
		*stack = (*stack)->next;
	}
}
