/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listmanip3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:04:13 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/03/11 17:28:44 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	findminmax(t_list *stack, t_minmax **minmax)
{
	(*minmax)->nbmin = stack->nbr;
	(*minmax)->nbmax = stack->nbr;
	while(stack->next)
	{
		stack = stack->next;
		if (stack->nbr < (*minmax)->nbmin)
			(*minmax)->nbmin = stack->nbr;
		if (stack->nbr > (*minmax)->nbmax)
			(*minmax)->nbmax = stack->nbr;
	}
}

int	ft_average(t_list *stack, int n)
{
	int	tot;
	int	qty;

	tot = 0;
	qty = 0;
	while (stack)
	{
		if (stack->nbr >= n)
		{
			tot+= stack->nbr;
			qty++;
		}
		stack = stack->next;
	}
	return (tot / qty);
}


/*n is the nbr of element to check if it's all the liste put a ft_lstsize*/
int	check_order(t_list *stack, char c, int n)
{
	if (!stack)
		return (0);
	if (c == 'i')
	{
		while (n-- > 1 && stack->nbr < (stack->next)->nbr)
			stack = stack->next;
		if (n == 1)
			return (0);
		else
			return (1);
	}
	if (c == 'd')
	{
		while (n > 1 && stack->nbr > stack->next->nbr)
		{
			stack = stack->next;
			n--;
		}
		if (n == 1)
			return (0);
		else
			return (1);
	}
	return (1);
}
