/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:04:13 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/04/04 17:10:39 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checksorted_b(t_list **stackA, t_list **stackB)
{
	if (!(*stackB))
	{
		lst_del(stackA);
		return (1);
	}
	else if (check_order(*stackB, 'd', ft_lstsize(*stackB)) == 0)
	{
		pushback(stackA, stackB, ft_lstsize(*stackB));
		lst_del(stackA);
		return (1);
	}
	return (0);
}



int main(int argc, char **argv)
{
	int		op;
	t_list	*stackA;
	t_list	*stackB;
	int 	L;
	int		n;
	int i = 0;

	stackB = NULL;
	stackA = fill_list(argc, argv);
	if (checkarg(stackA) == 0 || checkintminmax(stackA) == 0)
	{
		printf("ERROR");
		lst_del(&stackA);
		return (0);
	}
	op = 0;
	ft_findposition(&stackA);
	L = ft_bestpartition(stackA);
	n = L;
//	ft_printf("L= %d, n=%d\n", L, n);
	if (ft_lstsize(stackA) < 8)
		smallsortA(&stackA, &stackB, ft_lstsize(stackA));
	else
	{
		while (check_order(stackA, 'i', ft_lstsize(stackA)))
		{
//			ft_printf("L= %d, n=%d\n", L, n);
//			ft_printf("n- %d\n", n);
			op = firstsortAB(&stackA, &stackB, L, n);
			L+= n;
		}
	}
	if (ft_checksorted_b(&stackA, &stackB))
		return (0);
//	printf("op=%d, n=%d",op,n);
//	print_stack(stackA, stackB);
//	printf("op = %d", op);
	while (stackB && i++ < 15)
	{
//		printf("op= %d", op);
		if (op == 0)
			op = n;
		while (op && stackB)
		{
			op = sortback(&stackA,&stackB, op);
			if (stackB && stackB->next)
				op = revrotsort(&stackA, &stackB, op);
			if (op)
			{
				while(stackB && (stackB)->position > (stackA)->position - op)
				{
					if ((stackB)->position == (stackA)->position - 1)
					{
						push(&stackB, &stackA);
						write (1, "pa\n", 3);
						op--;
					}
			 		else
					{
						rotate(&stackB);
						write(1, "rb\n", 3);
					}
				}
			}
		}
	}
//	print_stack(stackA, stackB);
	lst_del(&stackA);
	return (0);
}
