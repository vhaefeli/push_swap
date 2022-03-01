/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:04:13 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/03/01 18:06:32 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	firstsortAB(t_list **stackA, t_list **stackB)
{	
	int	op;
	int L;
	int n;

	op = 0;
	L = ft_lstsize(*stackA);
	n = middlevalue(*stackA);
	L--;
	printf("n=%d",n);
//	write(1,"A", 1);
	while (L--)
	{	
		swap_or_not(stackA, stackB);
		op = op + rotate_pushAB(stackA, stackB, n);
		printStack(*stackA, *stackB);		
	}
	if (*stackB && ft_smaller(*stackB, (*stackB)->next) && ft_bigger(*stackB, ft_lstlast(*stackB)))
	{
		swap(stackB);
		write(1, "sb\n",3);
	}
	op = op + rotate_pushAB(stackA, stackB, n);
	printStack(*stackA, *stackB);
//	write(1,"B", 1);
//	printf("OP=%d\n",op);
	return (op);
}


int	firstsortBA(t_list **stackA, t_list **stackB)
{	
	int	op;
	int L;
	int n;

	op = 0;
	L = ft_lstsize(*stackB);
	n = middlevalue(*stackB);
	L--;
//	printf("n=%d",n);
//	write(1,"A2", 1);
	while (L--)
	{	
		swap_or_not(stackA, stackB);
		op = op + rotate_pushBA(stackA, stackB, n);
		printStack(*stackA, *stackB);		
	}
	if (ft_smaller(*stackB, (*stackB)->next) && ft_bigger(*stackB, ft_lstlast(*stackB)))
	{
		swap(stackB);
		write(1, "sb\n",3);
	}
	op = op + rotate_pushBA(stackA, stackB, n);
	printStack(*stackA, *stackB);
//	write(1,"B", 1);
//	printf("OP=%d\n",op);
	return (op);
}
int	secondsort(t_list **stackA, t_list **stackB,int op)
{	
//	write(1,"C", 1);
	if (check_order(*stackA, 'i', ft_lstsize(*stackA)))
		while (op--)
		{
			swap_or_not2(stackA, stackB);
			push(stackA, stackB);
			write(1,"pb\n", 3);
		}
	op = firstsortBA(stackA, stackB);	
//	write(1,"D", 1);
	return (op);
}

