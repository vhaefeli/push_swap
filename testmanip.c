/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmanip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:38:46 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/02/23 13:38:52 by vhaefeli         ###   ########.fr       */
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

int main(int argc, char **argv)
{
	int		n;
	int		L;
	int		k
	t_list	*stackA;
	t_list	*stackB;

	stackB = NULL;
	k = 0;
	stackA = fill_list(argc, argv);
	if (!stackA)
	{
		printf("il y a eu une erreur de remplissage de la stack :-(");
		return (0);
	}
	printf("la stack s'est bien remplie\n\n");
	printf("#		stack A		stack B\n");
	printStack(stackA, stackB);
	printf("test de swap\n\n");
	swap(&stackA);
	printf("#		stack A		stack B\n");
	printStack(stackA, stackB);
	printf("test de push\n\n");
	push(&stackA, &stackB);
	printf("#		stack A		stack B\n");
	printStack(stackA, stackB);
	printf("test reverse rotate\n\n");
	rev_rotate(&stackA);
	printf("#		stack A		stack B\n");
	printStack(stackA, stackB);
	printf("test de rotate\n\n");
	rotate(&stackA);
	printf("#		stack A		stack B\n");
	printStack(stackA, stackB);
	return (0);
}



