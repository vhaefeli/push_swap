/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listmanip2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:04:13 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/02/17 10:48:54 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
	t_list	*temp;

	temp = ft_lstlast(*stack);
	temp->next = *stack;
	(*stack)->next = NULL;
	*stack = temp;
}

void rev_rotate(t_list **stack)
{
	t_liste *temp1;
	t_liste *temp2;

	if (!stack)
		return (NULL);
	temp1 = &stack;
	while (temp1->next->next)
		temp1 = temp1->next;
	temp2 = temp1->next;
	temp1->next = NULL;
	temp2->next = &stack;
	stack = *temp2;
}

void push(t_list **stack1, t_list **stack2)
{
	if (!stack2)
		stack2 = ft_lstnew(stack1->content);
	else
		stack2 = ft_lstadd_front(stack2, *stack1);
	
}

int main(int argc, char **argv)
{
	int 	op_nb;
	t_list	*stackA;
	t_list	*stackB;

	op_nb = 0;
	t


