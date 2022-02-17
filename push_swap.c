/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:04:13 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/02/17 10:48:54 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

typedef	struct	s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (!new)
		return ;
	new->next = *alst;
	*alst = new;
}

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = malloc(sizeof(*list));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}


t_list	*fill_list(int argc, char **argv)
{
	t_list	*stackA;
	t_list	*new;

	argc--;
	stackA = ft_lstnew(argv[argc]);
	argc--;
	while(argc > 0)
	{
		new = ft_lstnew(argv[argc]);
		ft_lstadd_front(&stackA, new);
		argc--;
	}
	return (stackA);
}

void swap(t_list *stack)
{
	int temp;

	if (!stack)
		return ;
	temp = stack->content;
	stack->content = stack->next->content;	
	stack->next->content = temp;
}

void rotate(t_list **stack)
{
	t_list	*temp;

	temp = ft_lstlast(*stack);
	temp->next = *stack;
	stack->next = NULL;
	*stack = temp;
}

void rev_rotate(t_list **stack)
{
	t_liste *temp1;
	t_liste *temp2;

	temp1 = &stack;
	if (!lst)
		return (NULL);
	while (lst->next)
	{

		lst = lst->next;
	return (lst);



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


