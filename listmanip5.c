/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:04:13 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/03/10 17:08:06 by vhaefeli         ###   ########.fr       */
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

	write(1,"firstsortBA\n",12);
	op = 0;
	L = ft_lstsize(*stackB);
	if (L < 8)
		smallsortB(stackA, stackB, L);
	else
	{
		n = middlevalue(*stackB);
		L--;
//		printf("n=%d",n);
		while (L--)
		{
//			printf("L=%d",L);	
			swap_or_not2(stackA, stackB);
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
	write(1,"secondsort\n",11);
//	write(1,"C", 1);
	if (check_order(*stackA, 'i', ft_lstsize(*stackA)))
		while (op-- && check_order(*stackA, 'i', op))
		{
			swap_or_not2(stackA, stackB);
			push(stackA, stackB);
			write(1,"pb\n", 3);
//			printStack(*stackA, *stackB);
		}
	op = firstsortBA(stackA, stackB);	

	return (op);
}

int smallsortA(t_list **stackA, t_list **stackB, int L)
{
	int k;
	int op;

	write(1,"smallsortA\n",11);
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
		while (stackB)
		{
			swap_or_not2(stackA, stackB);
			push(stackB , stackA);
			write(1, "pa\n", 3);
			op++;
	//		printStack(*stackA, *stackB);
		}
	}
	return (op);
}



int minisortA(t_list **stackA)
{
	write(1,"minisortA\n",10);

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

	write(1,"smallsortB\n",11);

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
//				printStack(*stackA, *stackB);
			}
			if (!check_order(*stackB, 'd', ft_lstsize(*stackB)))
					break;
			push(stackB , stackA);
			write(1, "pa\n", 3);
			op++;
			L--;
//			printStack(*stackA, *stackB);
		}
		while (*stackB)
		{
			swap_or_not2(stackA, stackB);
			push(stackB , stackA);
			write(1, "pa\n", 3);
			op++;
//			printStack(*stackA, *stackB);
		}
	}
	return (op);
}



int minisortB(t_list **stackB)
{
	write(1,"minisortB\n",10);

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
