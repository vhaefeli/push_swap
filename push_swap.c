/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:04:13 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/03/03 12:01:13 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int main(int argc, char **argv)
{
	int		op;
	t_list	*stackA;
	t_list	*stackB;

	stackB = NULL;
	stackA = fill_list(argc, argv);
	if (checkarg(stackA) == 0)
	{
		printf("ERROR");
		return (0);
	}
//	printf("la stack s'est bien remplie\n\n");
//	printStack(stackA, stackB);
	while (check_order(stackA, 'i', ft_lstsize(stackA)))
		op = firstsortAB(&stackA, &stackB);
//	printStack(stackA, stackB);
//	printf("OP:%d\n",op);
	if (!stackB)
	{
//		write(1, "\nsorted!\n", 9);
		lst_del(&stackA);
		return (0);
	}
	if (check_order(stackB, 'd', ft_lstsize(stackB)) == 0)
	{
		pushback(&stackA, &stackB, ft_lstsize(stackB));
//		printStack(stackA, stackB);
//		write(1, "\nsorted!\n", 9);
		lst_del(&stackA);
		return (0);
	}
	if (check_order(stackB, 'd', op) == 0)
		pushback(&stackA, &stackB, op);
//	write(1,"\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n",32);
	op = firstsortBA(&stackA, &stackB);
//	printStack(stackA, stackB);
	while (check_order(stackB, 'd', ft_lstsize(stackB)) == 1 ||
			check_order(stackA, 'i', ft_lstsize(stackA)) == 1)
	{
		op = secondsort(&stackA, &stackB, op);
	}
	pushback(&stackA, &stackB, ft_lstsize(stackB));
	printStack(stackA, stackB);
//	write(1, "\nsorted!\n", 9);
	lst_del(&stackA);
	return (0);
}
