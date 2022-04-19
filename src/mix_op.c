/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mix_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:04:13 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/04/14 16:45:55 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_or_not(t_list **stack_a, t_list **stack_b)
{
	if (*stack_b && ft_bigger(*stack_a, (*stack_a)->next) && ft_smaller(*stack_b, (*stack_b)->next))
	{
		swap(stack_a);
		swap(stack_b);
		write(1, "ss\n",3);
	}
	else if (ft_bigger(*stack_a, (*stack_a)->next))
	{
		swap(stack_a);
		write(1, "sa\n",3);
	}
	else if (*stack_b && ft_smaller(*stack_b, (*stack_b)->next))
	{
		swap(stack_b);
		write(1, "sb\n",3);
	}
	else
		return (0);
	return (1);
}

int	rotate_push(t_list **stack_a, t_list **stack_b, int L, int n)
{
//	write(1,"R",1);
	if (*stack_b && ft_biggernb(*stack_a, L) && ft_biggernb(*stack_b, L - (n / 2) - 1))
	{
		rotate(stack_a);
		rotate(stack_b);
		write(1, "rr\n", 3);
	}
	else if (!ft_smallernb(*stack_a, L))
	{
		rotate(stack_a);
		write(1, "r\n", 3);
	}
	else if (*stack_b && ft_biggernb(*stack_b, L - (n / 2) - 1))
	{
		rotate(stack_b);
		push(stack_a, stack_b);
		write(1, "rb\npb\n", 6);
		return (1);
	}
	else
	{
		push(stack_a, stack_b);
		write(1, "pb\n", 3);
		return (1);
	}
	return (0);
}

int	rotate_swap(t_list **stack_a, t_list **stack_b)
{
	if (ft_smaller(*stack_a, ft_lstlast(*stack_a)) && ft_smallernb(*stack_a, (ft_lstsize(*stack_a) / 2)))
	{
		rev_rotate(stack_a);
		write(1, "rra\n",4);
	}
	else if (*stack_b && ft_bigger(*stack_a, ft_lstlast(*stack_a)) && ft_smaller(*stack_b, ft_lstlast(*stack_b)))
	{ 
		rotate(stack_a);
		rotate(stack_b);
		write(1, "rr\n",3);
	}
	else if (ft_bigger(*stack_a, ft_lstlast(*stack_a)))
	{
		rotate(stack_a);
		write(1, "ra\n",3);
	}
	else if (*stack_b && ft_smaller(*stack_b, ft_lstlast(*stack_b)) )
	{
		rotate(stack_b);
		write(1, "rb\n", 3);
	}
	else
		return (swap_or_not(stack_a, stack_b));
	return (1 + swap_or_not(stack_a, stack_b));
}
