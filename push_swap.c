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

#include <push_swap.h>

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

int main(int argc, char **argv)
{
	int		*argv_int,
	int		i;
	t_list	*stackA;
	t_list	*stackB;

	i = 0;
	while (i < argc)
	{
		argv_int[i] = ft_atoi
	stackA = fill_list(argc


