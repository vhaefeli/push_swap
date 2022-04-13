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

int smallsortA(t_list **stackA, t_list **stackB, int L)
{
	int k;
	int op;

//	write(1,"smallsortA\n",11);
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
			}
			if (!check_order(*stackA, 'i', ft_lstsize(*stackA)))
					break;
			push(stackA , stackB);
			write(1, "pb\n", 3);
			op++;
			L--;
	//		printStack(*stackA, *stackB);
		}
		while (*stackB)
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
//	write(1,"minisortA\n",10);
	if (ft_lstsize(*stackA) < 3)
	{
		if ((*stackA)->next && (*stackA)->position > (*stackA)->next->position)
		{
			swap(stackA);
			write(1, "sa\n", 3);
		}
	}
	else
	{
		if ((*stackA)->next->position > ft_lstlast(*stackA)->position)
		{
			if ((*stackA)->position > (*stackA)->next->position)
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
		if ((*stackA)->position > ft_lstlast(*stackA)->position)
		{
			rotate(stackA);
			write(1, "ra\n", 3);
		}
		if ((*stackA)->position > (*stackA)->next->position)
		{
			swap(stackA);
			write(1, "sa\n", 3);
		}
	}
	return (0);
}

int smallsortB(t_list **stackA, t_list **stackB, int L)
{
	int k;
	int op;

//	write(1,"smallsortB\n",11);

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
//
	if ((*stackB)->next && ft_lstsize(*stackB) < 3)
	{
		if ((*stackB)->position < (*stackB)->next->position)
		{
			swap(stackB);
			write(1, "sb\n", 3);
		}
	}

	if ((*stackB)->next->position < ft_lstlast(*stackB)->position)
	{
		if ((*stackB)->position < (*stackB)->next->position)
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
	if ((*stackB)->position < ft_lstlast(*stackB)->position)
	{
		rotate(stackB);
		write(1, "rb\n", 3);
	}
	if ((*stackB)->position < (*stackB)->next->position)
	{
		swap(stackB);
		write(1, "sb\n", 3);
	}
	return (0);
}

void pushback(t_list **stackA, t_list **stackB, int n)
{
//	write(1,"Pushback\n", 9);
	if (n == 0)
	{
		while ((*stackB)->next != NULL)
		{
			push(stackB, stackA);
			write(1, "pa\n", 3);
//			printStack(*stackA, *stackB);
		}
	}
	else
	{
//		printf("\nn:%d\n",n);
		while (n > 0 )
		{
			push(stackB, stackA);
			write(1, "pa\n", 3);
//			printStack(*stackA, *stackB);
			n--;
		}
	}
//	write(1, "\n pushend\n", 10);
}
