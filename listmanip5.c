/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:04:13 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/03/04 14:18:45 by vhaefeli         ###   ########.fr       */
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
//	printf("L=%d",L);
	if (L < 8)
		smallsortA(stackA, stackB, L);
	else
	{
		n = middlevalue(*stackA);
//		printf("n=%d",n);
		while (--L)
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
		op = op + rotate_pushAB(stackA, stackB, n);
	}
//	printStack(*stackA, *stackB);
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
	if (L < 8)
		smallsortB(stackA, stackB, L);
	n = middlevalue(*stackB);
	L--;
//	printf("n=%d",n);
//	write(1,"A2", 1);
	while (L--)
	{
//		printf("L=%d",L);	
		swap_or_not(stackA, stackB);
		op = op + rotate_pushBA(stackA, stackB, n);
//		usleep(1000);
//		printStack(*stackA, *stackB);		
	}
	if (ft_smaller(*stackB, (*stackB)->next) && ft_bigger(*stackB, ft_lstlast(*stackB)))
	{
		swap(stackB);
		write(1, "sb\n",3);
	}
	op = op + rotate_pushBA(stackA, stackB, n);
//	printStack(*stackA, *stackB);
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

int smallsortA(t_list **stackA, t_list **stackB, int L)
{
	int k;
	int op;

	op = 0;
	if (L < 4)
		minisortA(stackA);
	else
	{
		while (L > 2)
		{
			k = 1;
			while (k)
			{
				k = rotate_swap(stackA, stackB);
	//			printStack(*stackA, *stackB);
			}
			if (!check_order(*stackA, 'i', ft_lstsize(*stackA)))
					break;
			push(stackA , stackB);
			write(1, "pb\n", 3);
			op++;
			L--;
	//		printStack(*stackA, *stackB);
		}
		while ((*stackB)->next)
		{
			swap_or_not2(stackA, stackB);
			push(stackB , stackA);
			write(1, "pa\n", 3);
			op++;
	//		printStack(*stackA, *stackB);
		}

		push(stackB, stackA);
		write(1, "pa\n", 3);
		op++;
	//	printStack(*stackA, *stackB);
	}
	return (op);
}



int minisortA(t_list **stackA)
{
	if ((*stackA)->next->nbr > ft_lstlast(*stackA)->nbr)
	{
		if ((*stackA)->nbr > (*stackA)->next->nbr)
		{
			rotate(stackA);
			write(1, "ra\n", 3);
		}
		else
		{
			rev_rotate(stackA);
			write(1, "rra\n", 4);
		}
	}
	if ((*stackA)->nbr > ft_lstlast(*stackA)->nbr)
	{
		rotate(stackA);
		write(1, "ra\n", 3);
	}
	if ((*stackA)->nbr > (*stackA)->next->nbr)
	{
		swap(stackA);
		write(1, "sa\n", 3);
	}
	return (0);
}

int smallsortB(t_list **stackA, t_list **stackB, int L)
{
	int k;
	int op;

	op = 0;
	if (L < 4)
		minisortB(stackB);
	else
	{
		while (L > 2)
		{
			k = 1;
			while (k)
			{
	//			printf("k= %d",k);
				k = rotate_swap(stackA, stackB);
	//			printStack(*stackA, *stackB);
			}
			if (!check_order(*stackB, 'd', ft_lstsize(*stackB)))
					break;
			push(stackB , stackA);
			write(1, "pa\n", 3);
			op++;
			L--;
	//		printStack(*stackA, *stackB);
		}
		while ((*stackA)->next)
		{
			swap_or_not2(stackA, stackB);
			push(stackB , stackA);
			write(1, "pa\n", 3);
			op++;
	//		printStack(*stackA, *stackB);
		}

		push(stackB, stackA);
		write(1, "pa\n", 3);
		op++;
	//	printStack(*stackA, *stackB);
	}
	return (op);
}



int minisortB(t_list **stackB)
{
	if ((*stackB)->next->nbr > ft_lstlast(*stackB)->nbr)
	{
		if ((*stackB)->nbr > (*stackB)->next->nbr)
		{
			rotate(stackB);
			write(1, "rb\n", 3);
		}
		else
		{
			rev_rotate(stackB);
			write(1, "rrb\n", 4);
		}
	}
	if ((*stackB)->nbr > ft_lstlast(*stackB)->nbr)
	{
		rotate(stackB);
		write(1, "rb\n", 3);
	}
	if ((*stackB)->nbr > (*stackB)->next->nbr)
	{
		swap(stackB);
		write(1, "sb\n", 3);
	}
	return (0);
}
