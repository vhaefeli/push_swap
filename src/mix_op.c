/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mix_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:04:13 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/04/21 10:34:11 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_or_not(t_list **stack_a, t_list **stack_b)
{
	if (*stack_b && ft_bigger(*stack_a, (*stack_a)->next)
		&& ft_smaller(*stack_b, (*stack_b)->next))
	{
		swap(stack_a, NULL);
		swap(stack_b, "ss");
	}
	else if (ft_bigger(*stack_a, (*stack_a)->next))
		swap(stack_a, "sa");
	else if (*stack_b && ft_smaller(*stack_b, (*stack_b)->next))
		swap(stack_b, "sb");
	else
		return (0);
	return (1);
}

int	rotate_push(t_list **stack_a, t_list **stack_b, int L, int n)
{
	if (*stack_b && ft_biggernb(*stack_a, L)
		&& ft_biggernb(*stack_b, L - (n / 2) - 1))
	{
		rotate(stack_a, NULL);
		rotate(stack_b, "rr");
	}
	else if (!ft_smallernb(*stack_a, L))
		rotate(stack_a, "ra");
	else if (*stack_b && ft_biggernb(*stack_b, L - (n / 2) - 1))
	{
		rotate(stack_b, "rb");
		return (push(stack_a, stack_b, "pb"));
	}
	else
		return (push(stack_a, stack_b, "pb"));
	return (0);
}

int	rotate_swap(t_list **stack_a, t_list **stack_b)
{
	int	nb;

	nb = ft_lstsize(*stack_a) / 2 + 1;
	if (ft_bigger(*stack_a, ft_lstlast(*stack_a))
		&& ft_smallernb(ft_lstlast(*stack_a), nb))
		rev_rotate(stack_a, "rra");
	else if (*stack_b && ft_bigger(*stack_a, ft_lstlast(*stack_a))
		&& ft_smaller(*stack_b, ft_lstlast(*stack_b)))
	{
		rotate(stack_a, NULL);
		rotate(stack_b, "rr");
	}
	else if (ft_bigger(*stack_a, ft_lstlast(*stack_a)))
		rotate(stack_a, "ra");
	else if (*stack_b && ft_smaller(*stack_b, ft_lstlast(*stack_b)))
		rotate(stack_b, "rb");
	else
		return (swap_or_not(stack_a, stack_b));
	return (1 + swap_or_not(stack_a, stack_b));
}
