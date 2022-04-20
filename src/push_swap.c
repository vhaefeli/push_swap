/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:04:13 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/04/20 16:27:23 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checksorted_b(t_list **stack_a, t_list **stack_b)
{
	if (!(*stack_b))
	{
		lst_del(stack_a);
		return (1);
	}
	else if (check_order(*stack_b, 'd', ft_lstsize(*stack_b)) == 0)
	{
		pushback(stack_a, stack_b, ft_lstsize(*stack_b));
		lst_del(stack_a);
		return (1);
	}
	return (0);
}

int main(int argc, char **argv)
{
	int		op;
	t_list	*stack_a;
	t_list	*stack_b;
	t_op	analysis;
	
	if (argc == 1 || ft_ini(argc, argv, &stack_a, &analysis) == 1)
		return (0);
	stack_b = NULL;
	if (ft_lstsize(stack_a) < 8)
		smallsort(&stack_a, &stack_b, ft_lstsize(stack_a));
	else
	{
		while (check_order(stack_a, 'i', ft_lstsize(stack_a)))
		{
			op = firstsort(&stack_a, &stack_b, analysis.op, analysis.split);
			analysis.op+= analysis.split;
		}
	}
	if (ft_checksorted_b(&stack_a, &stack_b))
		return (0);
	if (op == 0)
		op = analysis.split;
	while (op != 0 && stack_b)
	{
		backsort(&stack_a, &stack_b, op);
		op -= push(&stack_b, &stack_a, "pa");
		if (op == 0)
			op = analysis.split;
	}
	lst_del(&stack_a);
	return (0);
}
