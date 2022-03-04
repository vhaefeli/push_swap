/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinto-r <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:04:13 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/03/04 02:15:47 by rpinto-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void print_array(char **strs)
{
	int i;

	i = 0;
	while (strs && strs[i])
		printf("%d\n", ft_atoi(strs[i++]));
}

void free_array(char **strs)
{
	int i;

	i = 0;
	while (strs && strs[i])
		free(strs[i++]);
	free(strs);
}

int is_invalid_numbers(char **strs)
{
	int i;
	int j;

	i = 0;
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
		{
			if (strs[i][j] == '-' && j == 0)
				j++;
			if (ft_isdigit(strs[i][j]) != 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	char **strs;

	if (argc == 2)
	{
		strs = ft_split(argv[1], ' ');
		if (is_invalid_numbers(strs))
			printf("Error: invalid numbers\n");
		free_array(strs);
	}
	else if (argc > 2)
	{
		if (is_invalid_numbers(++argv))
			printf("Error: invalid numbers\n");
	}
	else
		printf("Error: too few arguments\n");
	return (0);
}
