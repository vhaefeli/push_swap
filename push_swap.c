/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:04:13 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/02/25 16:13:31 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	firstsort(t_list **stackA, t_list **stackB)
{	
	int	op;
	int L;
	int n;

	op = 0;
	L = ft_lstsize(*stackA);
	n = middlevalue(*stackA);
	L--;
	printf("n=%d",n);
	write(1,"A", 1);
	while (L--)
	{	
		swap_or_not(stackA, stackB);
		op = op + rotate_push(stackA, stackB, n);
		printStack(*stackA, *stackB);		
	}
	if (*stackB && ft_smaller(*stackA, (*stackB)->next) && ft_bigger(*stackB, ft_lstlast(*stackB)))
	{
		swap(stackB);
		write(1, "sb\n",3);
	}
	op = op + rotate_push(stackA, stackB, n);
	printStack(*stackA, *stackB);
	write(1,"B", 1);
	printf("OP=%d\n",op);
	return (op);
}


int	firstsortBA(t_list **stackB, t_list **stackA)
{	
	int	op;
	int L;
	int n;

	op = 0;
	L = ft_lstsize(*stackB);
	n = middlevalue(*stackB);
	L--;
	printf("n=%d",n);
	write(1,"A2", 1);
	while (L--)
	{	
		swap_or_not(stackA, stackB);
		op = op + rotate_pushBA(stackA, stackB, n);
		printStack(*stackA, *stackB);		
	}
	if (*stackB && ft_smaller(*stackA, (*stackB)->next) && ft_bigger(*stackB, ft_lstlast(*stackB)))
	{
		swap(stackB);
		write(1, "sb\n",3);
	}
	op = op + rotate_push(stackA, stackB, n);
	printStack(*stackA, *stackB);
	write(1,"B", 1);
	printf("OP=%d\n",op);
	return (op);
}
int	secondsort(t_list **stackA, t_list **stackB,int op)
{	
	write(1,"C", 1);
	while (op--)
	{
		swap_or_not(stackA, stackB);
		push(stackA, stackB);
		write(1,"pb\n", 3);
	}
	op = firstsort(stackB, stackA);	
	write(1,"D", 1);
	return (op);
}

int main(int argc, char **argv)
{
	int		op;
	t_list	*stackA;
	t_list	*stackB;

	stackB = NULL;
	stackA = fill_list(argc, argv);
	if (!stackA)
	{
		printf("il y a eu une erreur de remplissage de la stack :-(");
		return (0);
	}
	printf("la stack s'est bien remplie\n\n");
	printStack(stackA, stackB);
	while (check_order(stackA, 'i',ft_lstsize(stackA)))
		op = firstsort(&stackA, &stackB);	
//	printStack(stackA, stackB);
//	printf("OP:%d\n",op);
	if (check_order(stackB, 'd', ft_lstsize(stackB)) == 0)
	{
		pushback(&stackA, &stackB, ft_lstsize(stackB));
		printStack(stackA, stackB);
		lst_del(&stackA);
		return (0);
	}
	if (check_order(stackB, 'd', op) == 0)
		pushback(&stackA, &stackB, op);
	op = firstsort(&stackB, &stackA);
	printStack(stackA, stackB);
	return (0);
	while (check_order(stackB, 'd', ft_lstsize(stackB)) == 1 ||
			check_order(stackA, 'i', ft_lstsize(stackA)) == 1)
	{
		op = secondsort(&stackA, &stackB, op);
	}
	pushback(&stackA, &stackB, ft_lstsize(stackB));
//	printStack(stackA, stackB);
	write(1, "\nTRIE!!!\n", 9);
	lst_del(&stackA);
	return (0);
}
