/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:04:13 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/01/28 17:08:53 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_bucket
{
	int quantity;
	int	*stack_a;
	int	*stack_b;
}	t_bucket;


void	check_order(t_bucket *bucket)
{
	if (bucket->stack_a[0] > bucket->stack_a[1] && quantityb > 1 &&
			bucket->stack_b[0] < bucket->stack_b[1])
		swap_ab(bucket->stack_a, bucket->stack_b);
	else if (bucket->stack_a[0] > bucket->stack_a[1])
		swap_a(bucket->stack_a);
	else if (bucket->stack_b[0] < bucket->stack_b[1] && quantityb > 1)
		swap_b(bucket->stack_b);
	if (bucket->stack_a[0] > bucket->stack_a[quantitya - 1] && quantityb > 1 &&
			bucket->stack_b[0] < bucket->stack_b[quantityb - 1])
		reverserot_ab(bucket->stack_a, bucket->stack_b);
	else if (bucket->stack_a[0] > bucket->stack_a[quantitya - 1])
		reverserot_a(bucket->stack_a);
	else if (bucket->stack_b[0] < bucket->stack_b[quantityb -1])
		reverserot_b(bucket->stack_b);
}

void	push_swap(t_bucket *bucket)
{
	int quantitya;
	int quantityb;
	
	quantitya = bucket->quantity;
	quantityb = 0;
	while (quantitya > 2)
	{
		check_order(bucket);
		push_tont(bucket->stack_a, bucket->stack_b);
		write(1, "pb\n", 3);
		quantitya--;
		quantityb++;
	}
	while (quantityb > 0)
	{
		check_order(bucket);
		push_tont(bucket->stack_b, bucket->stack_a);
		write(1, "pa\n", 3);
		quantityb--;
		quantitya++;
	}
}

int	ft_error(void)
	{
		write(1, "ERROR\n", 6); 
		return (0);
	}

int main(int argc, char **argv)
{
	t_bucket	*bucket;
	int			i;

	i = 0;
	if (argc <= 1)
		return (ft_error());
	if (argc = 2)
		return(0);
	bucket = malloc((2 * (argc - 1)+ 1)*(size of int));
	if (!bucket)
		return (ft_error());
	bucket->quantity = argc - 1;
	while (i < argc -1)
	{
		bucket->stack_a[i] = argv[i + 1];
		i++;
	}
	if (bucket->quantity = 2)
	{
		if (bucket->stack_a[0] > bucket->stack_a[1])
			swap_a(bucket->stack_a);
	}
	else
		push_swap(bucket);
	return (0);
}
