/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis_ft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:04:13 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/04/20 13:10:13 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*findmin(t_list *stack)
{
	t_list	*min;

	min = stack;
	while (stack->next)
	{
		stack = stack->next;
		if (stack->nbr < min->nbr)
			min = stack;
	}
	return (min);
}

/*n is the nbr of element to check if it's all the liste put a ft_lstsize*/
int	check_order(t_list *stack, char c, int n)
{
	if (!stack || !stack->next)
		return (0);
	if (c == 'i')
	{
		while (n-- > 1 && stack->position == ((stack->next)->position) - 1)
			stack = stack->next;
		if (n == 0)
			return (0);
		else
			return (1);
	}
	if (c == 'd')
	{
		while (n-- > 1 && stack->position == ((stack->next)->position) + 1)
			stack = stack->next;
		if (n == 0)
			return (0);
		else
			return (1);
	}
	return (1);
}

void	print_stack(t_list *stack_a, t_list *stack_b)
{
	int	i;

	i = 1;
	ft_printf("\n#		stack_a		stack_b\n");
	while (stack_a != NULL || stack_b != NULL)
	{
		ft_printf("%i		", i);
		if (stack_a != NULL)
			ft_printf("%d.%s		", stack_a->position, stack_a->src);
		else
			ft_printf("		");
		if (stack_b != NULL)
			ft_printf("%d.%s\n", stack_b->position, stack_b->src);
		else
			ft_printf("\n");
		if (stack_a != NULL)
			stack_a = stack_a->next;
		if (stack_b != NULL)
			stack_b = stack_b->next;
		i++;
	}
}
