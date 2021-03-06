/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortsmall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:04:13 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/04/21 10:33:15 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	smallsort(t_list **stack_a, t_list **stack_b, int L)
{
	int	k;
	int	op;

	op = 0;
	if (L < 4)
		minisort(stack_a);
	else
	{
		while (L > 2)
		{
			k = 1;
			while (k)
				k = rotate_swap(stack_a, stack_b);
			if (!check_order(*stack_a, 'i', ft_lstsize(*stack_a)))
				break ;
			op += push(stack_a, stack_b, "pb");
			L--;
		}
		while (*stack_b)
		{
			swap_or_not(stack_a, stack_b);
			op += push(stack_b, stack_a, "pa");
		}
	}
	return (op);
}

int	minisort(t_list **stack_a)
{
	if (ft_lstsize(*stack_a) < 3)
	{
		if ((*stack_a)->next
			&& (*stack_a)->position > (*stack_a)->next->position)
			swap(stack_a, "sa");
	}
	else
	{
		if ((*stack_a)->next->position > ft_lstlast(*stack_a)->position)
		{
			if ((*stack_a)->position > (*stack_a)->next->position)
				rotate(stack_a, "ra");
			else
				rev_rotate(stack_a, "rra");
		}
		if ((*stack_a)->position > ft_lstlast(*stack_a)->position)
			rotate(stack_a, "ra");
		if ((*stack_a)->position > (*stack_a)->next->position)
			swap(stack_a, "sa");
	}
	return (0);
}

void	pushback(t_list **stack_a, t_list **stack_b, int n)
{
	if (n == 0)
	{
		while ((*stack_b)->next != NULL)
			push(stack_b, stack_a, "pa");
	}
	else
	{
		while (n > 0 )
		{
			push(stack_b, stack_a, "pa");
			n--;
		}
	}
}
