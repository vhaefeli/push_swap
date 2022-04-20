/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillcheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:04:13 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/04/20 16:30:30 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ini(int argc, char **argv, t_list **stack_a, t_op *analysis)
{
	*stack_a = fill_list(argc, argv);
	if (checkarg(*stack_a) == 0 || checkintminmax(*stack_a) == 0)
	{
		lst_del(stack_a);
		ft_printf("Error");
		return (1);
	}
	ft_findposition(stack_a);
	analysis->sizetot = ft_lstsize(*stack_a);
	analysis->split = ft_bestpartition(*stack_a);
	analysis->op = analysis->split;
	return (0);
}

t_list	*fill_list(int nbn, char **nb)
{
	t_list	*stack_a;
	t_list	*new;

	if (nbn < 2)
		return (NULL);
	if (nbn == 2)
		stack_a = ft_splittolst(nb[1]);
	else
	{
		nbn--;
		stack_a = ft_lstnew2(nb[nbn]);
		nbn--;
		while (nbn > 0)
		{
			new = ft_lstnew2(nb[nbn]);
			ft_lstadd_front(&stack_a, new);
			nbn--;
		}
	}
	return (stack_a);
}

t_list	*ft_splittolst(char *str)
{
	t_list	*stack_a;
	t_list	*new;
	char	*temp;

	stack_a = NULL;
	while (*str)
	{
		temp = str;
		while (*str != ' ' && *str != '\0')
			str++;
		if (*str == ' ')
		{
			*str = '\0';
			str++;
		}
		while (*str == ' ')
			str++;
		new = ft_lstnew2(temp);
		if (stack_a)
			ft_lstadd_back(&stack_a, new);
		else
			stack_a = ft_lstnew2(temp);
	}
	return (stack_a);
}

int	checkarg(t_list *stack)
{
	t_list	*temp;

	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->nbr == 0)
		{
			while (*(stack->src))
			{
				if (*(stack->src) != '0')
					return (0);
				(stack->src)++;
			}
		}
		temp = stack;
		while (temp->next)
		{
			if (stack->nbr == temp->next->nbr)
				return (0);
			temp = temp->next;
		}
		stack = stack->next;
	}
	return (1);
}

int	checkintminmax(t_list *stack)
{
	char	*numberchar;

	while (stack)
	{
		if (ft_strlen(stack->src) > 9)
		{
			numberchar = ft_itoa(stack->nbr);
			while (*(stack->src))
			{
				if (*(stack->src) == '+')
					(stack->src)++;
				if (*(stack->src) != *numberchar)
					return (0);
				(stack->src)++;
				numberchar++;
			}
		}
		stack = stack->next;
	}
	return (1);
}
