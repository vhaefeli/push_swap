/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis_ft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:04:13 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/04/14 16:05:21 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*findmin(t_list *stack)
{
	t_list	*min;

	min = stack;
	while(stack->next)
	{
		stack = stack->next;
		if (stack->nbr < min->nbr)
			min = stack;
	}
	return (min);
}

/*n is the nbr of element to check if it's all the liste put a ft_lstsize*/
int	check_order(t_list *stack, char c, int n)
{
	if (!stack || !stack->next)
		return (0);
	if (c == 'i')
	{
		while (n-- > 1 && stack->position == ((stack->next)->position) - 1)
			stack = stack->next;
		if (n == 0)
			return (0);
		else
			return (1);
	}
	if (c == 'd')
	{
		while (n-- > 1 && stack->position == ((stack->next)->position) + 1)
			stack = stack->next;
		if (n == 0)
			return (0);
		else
			return (1);
	}
	return (1);
}
