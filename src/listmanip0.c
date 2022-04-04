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

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

static unsigned long	ft_inttolu(int n)
{
	unsigned long	nb;

	if (n < 0)
		nb = -((unsigned long)n);
	else
		nb = (unsigned long)n;
	return (nb);
}

static unsigned long	ft_unitp10(unsigned long nb)
{
	unsigned long	d;

	d = 1;
	if (nb == 0)
		return (1);
	while (nb)
	{
		d *= 10;
		nb /= 10;
	}
	return (d / 10);
}

size_t	ft_ln(int n)
{
	size_t	l;

	l = 0;
	if (n <= 0)
		l = 1;
	while (n)
	{
		l++;
		n /= 10;
	}
	return (l);
}

char	*ft_itoa(int n)
{
	char			*nbr;
	unsigned long	nb;
	size_t			i;
	size_t			d;
	size_t			l;

	i = 0;
	l = ft_ln(n);
	nb = ft_inttolu(n);
	d = ft_unitp10(nb);
	nbr = malloc(l + 1);
	if (!nbr)
		return (NULL);
	if (n < 0)
		nbr[i++] = '-';
	while (i < l)
	{
		nbr[i++] = '0' + ((nb / d) % 10);
		d = d / 10;
	}
	nbr[i] = '\0';
	return (nbr);
}

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
			while(*(stack->content))
			{
				if (*(stack->content) != '0')
				   return (0);
				(stack->content)++;
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
		if (ft_strlen(stack->content) > 9)
		{
			numberchar = ft_itoa(stack->nbr);
			while(*(stack->content))
			{
				if (*(stack->content) == '+')
					(stack->content)++;
				if (*(stack->content) != *numberchar)
				   return (0);
				(stack->content)++;
				numberchar++;
			}
		}
		stack = stack->next;
	}
	return (1);
}

