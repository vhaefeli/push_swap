/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listmanip3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:04:13 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/03/04 11:28:36 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoistrong(const char *str)
{
	int	nb;
	int	sig;

	nb = 0;
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
			nb = (nb * 10) + (*str - 48);
		}
		else
			return (0);
		str++;
	}
	return (nb * sig);
}

int	ft_bigger(t_list *stack1, t_list *stack2)
{
	if (!stack1 || !stack2)
		return (0);
	if (stack1->position > stack2->position)
		return (1);
	else
		return (0);
}

int	ft_smaller(t_list *stack1, t_list *stack2)
{
	if (!stack1 || !stack2)
		return (0);
	if (stack1->position < stack2->position)
		return (1);
	else
		return (0);
}

int	ft_biggernb(t_list *stack1, int n)
{
	if (!stack1)
		return (0);
	if (stack1->position > n)
		return (1);
	else
		return (0);
}

int	ft_smallernb(t_list *stack1, int n)
{
	if (!stack1)
		return (0);
	if (stack1->position < n)
		return (1);
	else
		return (0);
}
