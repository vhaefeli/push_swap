#include "push_swap.h"

void	ft_findposition(t_list **stack)
{
	int		qty;
	int 	pos;
	t_list	*min;

	pos = 1;
	qty = ft_lstsize(*stack);
	while (qty--)
	{
		min = findmin(*stack);
		min->position = pos;
		pos++;
		min->nbr = INT_MAX;
	}
}

int	ft_bestpartition(t_list *stack)
{
	int qty;

	qty = ft_lstsize(stack);
	if (qty < 8)
		return (qty);
	else if (qty < 24)
		qty/= 2;
	else if (qty <= 50)
		qty/= 3;
	else if (qty <= 100)
		qty/= 9;
	else if (qty <= 200)
		qty/= 8;
	else if (qty <= 500)
		qty/= 20;
	else
		qty/= 50;
	return (qty);
}
