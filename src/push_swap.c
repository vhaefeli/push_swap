/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:04:13 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/04/19 18:34:15 by vhaefeli         ###   ########.fr       */
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
//	int i = 0;
	
	if (ft_ini(argc, argv, &stack_a, &analysis) == 1)
		return (0);
	stack_b = NULL;
	//	print_stack(stack_a, stack_b);
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
//	print_stack(stack_a, stack_b);
	ft_printf("op = %d, a.op = %d, a.split = %d\n", op , analysis.op, analysis.split);
//	return (0);
	while (op != 0 && stack_b)
	{
		op = sortback(&stack_a,&stack_b, op);
		if (stack_b && stack_b->next)
			op = revrotsort(&stack_a, &stack_b, op);
		if (op)
		{
//				ft_printf("1:%d\n 2:%d\n", stack_b->position, stack_a->position - op);
			while(stack_b && (stack_b)->position > (stack_a)->position - op)
			{
				if ((stack_b)->position == (stack_a)->position - 1)
				{
					push(&stack_b, &stack_a);
					write (1, "pa\n", 3);
					op--;
				}
		 		else
				{
					rotate(&stack_b);
					write(1, "rb\n", 3);
				}
			}			
		}
			if (op < 1)
			{
				print_stack(stack_a, stack_b);
				ft_printf("OP=%d\n", op);
				op = analysis.split + op;
			}
	}
//		print_stack(stack_a, stack_b);
	lst_del(&stack_a);
	return (0);
}
