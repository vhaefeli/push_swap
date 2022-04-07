/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listmanip0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:04:13 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/03/04 18:47:31 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*fill_list(int nbn, char **nb)
{
	t_list	*stackA;
	t_list	*new;

	if (nbn < 2)
		return (NULL);
	if (nbn == 2)
		stackA = ft_splittolst(nb[1]);
	else
	{
		nbn--;
		stackA = ft_lstnew2(nb[nbn]);
		nbn--;
		while(nbn > 0)
		{
			new = ft_lstnew2(nb[nbn]);
			ft_lstadd_front(&stackA, new);
			nbn--;
		}
	}
	return (stackA);
}

t_list	*ft_splittolst(char *str)
{
	t_list	*stackA;
	t_list	*new;
	char	*temp;

	temp = str;
	while( *str != ' ' && *str != '\0')
		str++;
	if (*str == '\0')
		return (NULL);
	*str = '\0';
	str++;
	stackA = ft_lstnew2(temp);
	while (*str)
	{
		temp = str;
		while( *str != ' ' && *str != '\0')
			str++;
		if (*str == ' ')
		{
			*str = '\0';
			str++;
		}
		while (*str == ' ')
			str++;	
		new = ft_lstnew2(temp);
		ft_lstadd_back(&stackA, new);
	}
	return (stackA);
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
			while(*(stack->src))
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
			while(*(stack->src))
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

void print_stack(t_list *stackA, t_list *stackB)
{
	int i;

	i = 1;
	printf("\n#		stackA		stackB\n");
	while  (stackA != NULL || stackB != NULL)
	{
		ft_printf("%i		", i);
		if (stackA != NULL)
			ft_printf("%s		", stackA->src);
		else
			ft_printf("		");
		if (stackB != NULL)
			ft_printf("%s\n", stackB->src);
		else
			ft_printf("\n");
		if (stackA != NULL)
			stackA = stackA->next;
		if (stackB != NULL)
			stackB = stackB->next;
		i++;
	}
}
