/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listmanip3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:04:13 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/03/10 15:01:58 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void printStack(t_list *stackA, t_list *stackB)
{
	int i;

	i = 1;
	printf("\n#		stackA		stackB\n");
	while  (stackA != NULL || stackB != NULL)
	{
		printf("%i		", i);
		if (stackA != NULL)
			printf("%s		", stackA->content);
		else
			printf("		");
		if (stackB != NULL)
			printf("%s\n", stackB->content);
		else
			printf("\n");
		if (stackA != NULL)
			stackA = stackA->next;
		if (stackB != NULL)
			stackB = stackB->next;
		i++;
	}
}

int	check_order(t_list *stack, char c, int n)
// n is the nbr of element to check if it's all the liste put a ft_lstsize
{
	if (!stack)
		return (0);
	if (c == 'i')
	{
		while (n > 1 && stack->nbr < (stack->next)->nbr)
		{	
			stack = stack->next;
			n--;
		}
		if (n == 1)
			return (0);
		else
		{
			return (1);
		}
	}
	if (c == 'd')
	{
		while (n > 1 && stack->nbr > stack->next->nbr)
		{
			stack = stack->next;
			n--;
		}
		if (n == 1)
			return (0);
		else
			return (1);
	}
	return (1);
}

void	swap_or_not(t_list **stackA, t_list **stackB)
{
	if (*stackB && ft_bigger(*stackA, (*stackA)->next) && ft_smaller(*stackB, (*stackB)->next) && ft_bigger(*stackB, ft_lstlast(*stackB)))
	{
		swap(stackA);
		swap(stackB);
		write(1, "ss\n",3);
	}
	else if (ft_bigger(*stackA, (*stackA)->next))
	{
		swap(stackA);
		write(1, "sa\n",3);
	}
	else if (*stackB && ft_smaller(*stackB, (*stackB)->next) && ft_bigger(*stackB, ft_lstlast(*stackB)))
	{
		swap(stackB);
		write(1, "sb\n",3);
	}
}

int	swap_or_not2(t_list **stackA, t_list **stackB)
{
	if (*stackB && ft_bigger(*stackA, (*stackA)->next) && ft_smaller(*stackB, (*stackB)->next))
	{
		swap(stackA);
		swap(stackB);
		write(1, "ss\n",3);
	}
	else if (ft_bigger(*stackA, (*stackA)->next))
	{
		swap(stackA);
		write(1, "sa\n",3);
	}
	else if (*stackB && ft_smaller(*stackB, (*stackB)->next))
	{
		swap(stackB);
		write(1, "sb\n",3);
	}
	else
		return (0);
	return (1);
}

int	middlevalue(t_list *stack)
{
	int	L;
	int i;

	i = 1;
	L = ft_lstsize(stack);
	while (i < L / 2)
	{
		stack = stack->next;
		i++;
	}
	return (stack->nbr);
}

int	rotate_pushAB(t_list **stackA, t_list **stackB, int n)
{
//	write(1,"R",1);
	if (*stackB && ft_biggernb(*stackA, n) && ft_smaller(*stackB, ft_lstlast(*stackB)))
	{
		rotate(stackA);
		rotate(stackB);
		write(1, "rr\n",3);
	}
	else if (!ft_smallernb(*stackA, n))
	{
		rotate(stackA);
		write(1, "ra\n",3);
	}
	else if (*stackB && ft_smaller(*stackB, ft_lstlast(*stackB)))
	{
		rotate(stackB);
		push(stackA, stackB);
		write(1, "rb\npb\n", 6);
		return (1);
	}
	else
	{
		push(stackA, stackB);
		write(1, "pb\n", 3);
		return (1);
	}
	return (0);
}

int	rotate_pushBA(t_list **stackA, t_list **stackB, int n)
{
	if (ft_smallernb(*stackB, n))
	{
		rotate(stackB);
		write(1, "rb\n",3);
		return (2);
	}
	else
	{
		push(stackB, stackA);
		write(1, "pa\n", 3);
		return (1);
	}
	return (0);
}

int	rotate_swap(t_list **stackA, t_list **stackB)
{
	if (*stackB && ft_bigger(*stackA, ft_lstlast(*stackA)) && ft_smaller(*stackB, ft_lstlast(*stackB)))
	{
		rotate(stackA);
		rotate(stackB);
		write(1, "rr\n",3);
	}
	else if (ft_bigger(*stackA, ft_lstlast(*stackA)))
	{
		rotate(stackA);
		write(1, "ra\n",3);
	}
	else if (*stackB && ft_smaller(*stackB, ft_lstlast(*stackB)) )
	{
		rotate(stackB);
		write(1, "rb\n", 3);
	}
	else
		return (swap_or_not2(stackA, stackB));
	return (1 + swap_or_not2(stackA, stackB));
}

void pushback(t_list **stackA, t_list **stackB, int n)
{
	write(1,"Pushback\n", 9);
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

