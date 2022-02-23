/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listmanip3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:04:13 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/02/23 16:53:23 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	nbr;
	int	sig;

	nbr = 0;
	sig = 1;
	while (*str == ' ' || (*str > 8 && *str < 14))
		str++;
	if (*str == '-')
	{
		sig = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			nbr = (nbr * 10) + (*str - 48);
		}
		else
			return (nbr * sig);
		str++;
	}
	return (nbr * sig);
}

void printStack(t_list *stackA, t_list *stackB)
{
	int i;

	i = 1;
	printf("#		stackA		stackB\n");
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

int	check_order(t_list *stack, char c)
{
	int checked;

	if (c == 'i')
	{
		while (stack->next && stack->nbr < stack->next->nbr);
			stack = stack->next;
		if (stack->next = NULL)
			return (0);
		else
			return (1);
	}
	if (c == 'd')
	{
		while (stack->next && stack->nbr > stack->next->nbr);
			stack = stack->next;
		if (stack->next = NULL)
			return (0);
		else
			return (1);
	}
	return (1);
}

void	swap_or_not(t_list **stackA, t_list **stackB)
{
	if ((*stackA*)->nbr > (*stackA)->next->nbr &&
			(*stackB)->nbr < (*stackB)->next->nbr &&
			(*stackB)->nbr > ft_lstlast(*stackB)->nbr)
	{
		swap(stackA);
		swap(stackB);
		write(1, "ss\n",3);
	}
	else if ((*stackA)->nbr > (*stackA)->next->nbr)
	{
		swap(stackA);
		write(1, "sa\n",3);
	}
	else if ((*stackB)->nbr < (*stackB)->next->nbr) &&
			(*stackB)->nbr > ft_lstlast(*stackB)->nbr)
	{
		swap(stackB);
		write(1, "sb\n",3);
	}
}

int	middlevalue(t_list *stack)
{
	int	L;
	int i;

	i = 0;
	L = ft_lstsize(stack);
	while (i < L / 2)
	{
		stack = stack->next;
		i++;
	}
	return (stack->nbr);
}

int	rotate_push(t_list **stackA, t_list **stackB, int n)
{
	if ((*stackA)->nbr > n && (*stackB)->nbr < ft_lstlast(*stackB)->nbr)
	{
		rotate(stackA);
		rotate(stackB);
		write(1, "rr\n",3);
	}
	else if ((*stackA)->nbr > n)
	{
		rotate(stackA);
		write(1, "ra\n",3);
	}
	else if ((*stackB)->nbr < (*stackB)->next->nbr)
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

void pushback(t_list **stackA, t_list **stackB, int n)
{
	if (n == 0)
	{
		while ((*stackB)->next == NULL)
		{
			push(stackB, stackA);
			write(1, "pa\n", 3);
			*stackB = (*stackB)->next;
		}
	}
	else
	{
		while (n--)
		{
			push(stackB, stackA);
			write(1, "pa\n", 3);
			*stackB = (*stackB)->next;
		}
	}
}

