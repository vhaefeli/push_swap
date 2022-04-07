/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:04:13 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/03/11 17:28:22 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	firstsortAB(t_list **stackA, t_list **stackB)
{	
	int	op;
	int L;
	int n;

	write(1,"firstsortAB\n",12);
	op = 0;
	L = ft_lstsize(*stackA);
	if (L < 4)
		minisortA(stackA);
//	printStack(*stackA, *stackB);
//	printf("L=%d",L);
	else
	{
		n = middlevalue(*stackA);
//		printf("n=%d",n);
		while (L--)
		{	
			swap_or_not(stackA, stackB);
			op = op + rotate_pushAB(stackA, stackB, n);
//			printStack(*stackA, *stackB);		
		}
		if (*stackB && ft_smaller(*stackB, (*stackB)->next) &&
			   	ft_bigger(*stackB, ft_lstlast(*stackB)))
		{
			swap(stackB);
			write(1, "sb\n",3);
		}
	}
//	printf("OP=%d\n",op);
	return (op);
}

int	checkendsort(t_list *stack)
{
	int nb;

	nb = (stack)->nbr;
	while (stack)
	{
//		printf("nbr = %d\n",(stack)->nbr);
		if ((stack)->nbr > nb)
		   break;
		stack = (stack)->next;
	}
	if (!stack)
		return (1);
	else
		return (0);
}


int	firstsortBA(t_list **stackA, t_list **stackB)
{	
	int	op;
	int L;
	int n;
	int rp;

//	write(1,"firstsortBA\n",12);
	op = 0;
	L = ft_lstsize(*stackB);
	if (L < 8)
		smallsortB(stackA, stackB, L);
	else
	{
		n = middlevalue(*stackB);
//		printf("n=%d",n);
		while (L--)
		{
//			printf("L=%d",L);	
			swap_or_not2(stackA, stackB);
//			printStack(*stackA, *stackB);
			rp = rotate_pushBA(stackA, stackB, n);
//			printf("rp:%d\n",rp);
			if (rp == 2 && checkendsort(*stackB) == 1)
				break;
			if (rp == 1)
				op++;
//			printStack(*stackA, *stackB);		
		}
		if (ft_smaller(*stackB, (*stackB)->next) && ft_bigger(*stackB, ft_lstlast(*stackB)))
		{
			swap(stackB);
			write(1, "sb\n",3);
		}
//		printStack(*stackA, *stackB);
//		write(1,"B", 1);
//		printf("OP=%d\n",op);
	}
	return (op);
}
int	secondsort(t_list **stackA, t_list **stackB,int op)
{	
//	write(1,"secondsort\n",11);
//	write(1,"C", 1);
	if (check_order(*stackA, 'i', ft_lstsize(*stackA)))
		while (op-- && check_order(*stackA, 'i', op))
		{
			swap_or_not2(stackA, stackB);
			push(stackA, stackB);
			write(1,"pb\n", 3);
//		printStack(*stackA, *stackB);
		}
	op = firstsortBA(stackA, stackB);	

	return (op);
}