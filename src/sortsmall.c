/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortsmall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:04:13 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/04/19 11:39:03 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int smallsort(t_list **stack_a, t_list **stack_b, int L)
{
	int k;
	int op;

	op = 0;
	if (L < 4)
		minisort(stack_a);
	else
	{
		while (L > 2)
		{
			k = 1;
			while (k)
			{
				k = rotate_swap(stack_a, stack_b);
//				print_stack(*stack_a, *stack_b);
//
			}
			if (!check_order(*stack_a, 'i', ft_lstsize(*stack_a)))
					break;
			push(stack_a , stack_b);
			write(1, "pb\n", 3);
			op++;
			L--;
//			print_stack(*stack_a, *stack_b);
//
		}
		while (*stack_b)
		{
			swap_or_not(stack_a, stack_b);
			push(stack_b , stack_a);
			write(1, "pa\n", 3);
			op++;
//
//			print_stack(*stack_a, *stack_b);
		}
	}
	return (op);
}

int minisort(t_list **stack_a)
{
	if (ft_lstsize(*stack_a) < 3)
	{
		if ((*stack_a)->next && (*stack_a)->position > (*stack_a)->next->position)
		{
			swap(stack_a);
			write(1, "sa\n", 3);
		}
	}
	else
	{
		if ((*stack_a)->next->position > ft_lstlast(*stack_a)->position)
		{
			if ((*stack_a)->position > (*stack_a)->next->position)
			{
				rotate(stack_a);
				write(1, "ra\n", 3);
			}
			else
			{
				rev_rotate(stack_a);
				write(1, "rra\n", 4);
			}
		}
		if ((*stack_a)->position > ft_lstlast(*stack_a)->position)
		{
			rotate(stack_a);
			write(1, "ra\n", 3);
		}
		if ((*stack_a)->position > (*stack_a)->next->position)
		{
			swap(stack_a);
			write(1, "sa\n", 3);
		}
	}
	return (0);
}
/*
int smallsortB(t_list **stack_a, t_list **stack_b, int L)
{
	int k;
	int op;

	op = 0;
	if (L < 4)
		minisortB(stack_b);
	else
	{
		while (L > 2)
		{
			k = 1;
			while (k)
			{
				k = rotate_swap(stack_a, stack_b);
			}
			if (!check_order(*stack_b, 'd', ft_lstsize(*stack_b)))
					break;
			push(stack_b , stack_a);
			write(1, "pa\n", 3);
			op++;
			L--;
		}
		while (*stack_b)
		{
			swap_or_not2(stack_a, stack_b);
			push(stack_b , stack_a);
			write(1, "pa\n", 3);
			op++;
		}
	}
	return (op);
}



int minisortB(t_list **stack_b)
{
	write(1,"minisortB\n",10);
//
	if ((*stack_b)->next && ft_lstsize(*stack_b) < 3)
	{
		if ((*stack_b)->position < (*stack_b)->next->position)
		{
			swap(stack_b);
			write(1, "sb\n", 3);
		}
	}

	if ((*stack_b)->next->position < ft_lstlast(*stack_b)->position)
	{
		if ((*stack_b)->position < (*stack_b)->next->position)
		{
			rotate(stack_b);
			write(1, "rb\n", 3);
		}
		else
		{
			rev_rotate(stack_b);
			write(1, "rrb\n", 4);
		}
	}
	if ((*stack_b)->position < ft_lstlast(*stack_b)->position)
	{
		rotate(stack_b);
		write(1, "rb\n", 3);
	}
	if ((*stack_b)->position < (*stack_b)->next->position)
	{
		swap(stack_b);
		write(1, "sb\n", 3);
	}
	return (0);
}
*/
void pushback(t_list **stack_a, t_list **stack_b, int n)
{
	if (n == 0)
	{
		while ((*stack_b)->next != NULL)
		{
			push(stack_b, stack_a);
			write(1, "pa\n", 3);
		}
	}
	else
	{
		while (n > 0 )
		{
			push(stack_b, stack_a);
			write(1, "pa\n", 3);
			n--;
		}
	}
}
