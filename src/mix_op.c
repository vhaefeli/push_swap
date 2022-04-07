/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listmanip3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:04:13 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/03/11 17:28:44 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
