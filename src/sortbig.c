/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortbig.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:04:13 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/04/20 16:33:41 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	firstsort(t_list **stack_a, t_list **stack_b, int L, int n)
{	
	int	op;
	int	len;

	op = 0;
	len = ft_lstsize(*stack_a);
	if (len < 4)
		minisort(stack_a);
	else
	{
		while (len-- && (*stack_a)->next)
			op = op + rotate_push(stack_a, stack_b, L, n);
		if (*stack_b && ft_smaller(*stack_b, (*stack_b)->next)
			&& ft_bigger(*stack_b, ft_lstlast(*stack_b)))
			swap(stack_b, "sb");
	}
	L += n;
	return (op);
}

int	where_is_nb(t_list *stack_b, int min, int nb)
{
	while (stack_b->position != nb && stack_b->position >= min)
		stack_b = stack_b->next;
	if (stack_b->position == nb)
		return (0);
	else
		return (1);
}

void	backsort(t_list **stack_a, t_list **stack_b, int op)
{
	int	min;
	int	nb;
	int	w;

	min = (*stack_a)->position - op;
	nb = (*stack_a)->position - 1;
	w = where_is_nb(*stack_b, min, nb);
	if (w == 0)
	{
		while ((*stack_b)->position != nb)
		{
			rotate(stack_b, "rb");
			swap_or_not(stack_a, stack_b);
		}
	}
	else
	{	
		while ((*stack_b)->position != nb)
		{
			swap_or_not(stack_a, stack_b);
			rev_rotate(stack_b, "rrb");
		}
	}
}
