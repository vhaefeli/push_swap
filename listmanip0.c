/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listmanip2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:04:13 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/03/03 12:01:11 by vhaefeli         ###   ########.fr       */
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
	while( *str != ' ')
		str++;
	*str = '\0';
	str++;
	stackA = ft_lstnew2(temp);
	while (*str)
	{
		temp = str;
		while( *str != ' ')
			str++;
		*str = '\0';
		str++;
		new = ft_lstnew2(temp);
		ft_lstadd_back(&stackA, new);
	}
	return (stackA);
}

