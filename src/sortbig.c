/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortbig.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:04:13 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/04/19 18:34:26 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	firstsort(t_list **stack_a, t_list **stack_b, int L, int n)
{	
	int	op;
	int len;

	op = 0;
	len = ft_lstsize(*stack_a);
	if (len < 4)
		minisort(stack_a);
	else
	{
		while (len-- && (*stack_a)->next)
			op = op + rotate_push(stack_a, stack_b, L, n);
		if (*stack_b && ft_smaller(*stack_b, (*stack_b)->next) &&
			   	ft_bigger(*stack_b, ft_lstlast(*stack_b)))
		{
			swap(stack_b);
			write(1, "sb\n",3);
		}
	}
	return (op);
}
/*
int	checkendsort(t_list *stack)
{
	int nb;

	nb = (stack)->position;
	while (stack)
	{
		if ((stack)->position > nb)
		   break;
		stack = (stack)->next;
	}
	if (!stack)
		return (1);
	else
		return (0);
}
*/
int	sortback(t_list **stack_a, t_list **stack_b, int n)
{
	t_list	*temp1;

	temp1 = ft_lstlast(*stack_b);
	while (n > 0 && *stack_b)
	{
//		ft_printf("dede");
		swap_or_not(stack_a, stack_b);
		if ((*stack_b)->next && (temp1->position > (*stack_b)->position))
		{
			rev_rotate(stack_b);
			write(1, "rrb\n", 4);
			temp1 = ft_lstlast(*stack_b);
//			print_stack(*stack_a, *stack_b);
			ft_printf("n= %d", n);
		}
		if ((*stack_b)->position == (*stack_a)->position - 1)
		{
			push(stack_b, stack_a);
			write(1, "pa\n", 3);
			n--;
		}
		else if (((*stack_b)->next)->position == (*stack_a)->position -1)
		{
			if ((*stack_b)->position == (*stack_a)->position - 2)
			{
				push(stack_b, stack_a);
				write(1, "pa\n", 3);
				push(stack_b, stack_a);
				write(1, "pa\n", 3);
				n-= 2;
			}
			else
			{
				swap(stack_b);
				write(1, "sb\n",3);
			}
		}
		else
			break;
	}
	return (n);
}

int	revrotsort(t_list **stack_a, t_list **stack_b, int op)
{
	while ((*stack_b)->position != (*stack_a)->position - 1 && ft_lstlast(*stack_b)->position >= (*stack_a)->position - op)
	{
		rev_rotate(stack_b);
		write(1, "rrb\n", 4);
		swap_or_not(stack_a, stack_b);
	}
	if ((*stack_b)->position == (*stack_a)->position - 1)
		{
			push(stack_b, stack_a);
			write(1, "pa\n", 3);
			op--;
//			ft_printf("op=%d", op);
		}
	return (op);
}
