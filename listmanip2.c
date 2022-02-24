/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listmanip2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:04:13 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/02/24 13:46:28 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*fill_list(int nbn, char **nb)
{
	t_list	*stackA;
	t_list	*new;

	nbn--;
	stackA = ft_lstnew2(nb[nbn]);
	nbn--;
	while(nbn > 0)
	{
		new = ft_lstnew2(nb[nbn]);
		ft_lstadd_front(&stackA, new);
		nbn--;
	}
	return (stackA);
}

void swap(t_list **stack)
{
	t_list	*temp;

	if (!stack)
		return ;
	temp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;	
	temp->next = *stack;
	*stack = temp;
}

void rotate(t_list **stack)
{
	t_list	*temp1;
	t_list	*temp2;

	temp1 = ft_lstlast(*stack);
	temp1->next = *stack;
	temp2 = (*stack)->next;
	(*stack)->next = NULL;
	*stack = temp2;
}

void rev_rotate(t_list **stack)
{
	t_list	*temp1;
	t_list	*temp2;

	if (!stack)
		return ;
	temp1 = *stack;
	while (temp1->next->next)
		temp1 = temp1->next;
	temp2 = temp1->next;
	temp1->next = NULL;
	temp2->next = *stack;
	*stack = temp2;
}

void push(t_list **stack1, t_list **stack2)
{
	t_list *temp;

	if (!stack2)
	{
		temp = NULL;
		stack2 = stack1;
		*stack1 = (*stack1)->next;
		(*stack2)->next = NULL;
	}
	else
		temp = (*stack1)->next;
		ft_lstadd_front(stack2, *stack1);
		*stack1 = temp;
}
