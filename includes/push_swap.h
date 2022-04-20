/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:41:44 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/04/20 16:33:24 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

typedef struct s_op
{
	int	sizetot;
	int	split;
	int	op;
	int	error;
}	t_op;

t_list	*ft_lstnew2(char *src);
void	lst_del(t_list **stack);

void	ft_findposition(t_list **stack);
int		ft_bestpartition(t_list *stack);

void	swap(t_list **stack, char *src);
void	rotate(t_list **stack, char *src);
void	rev_rotate(t_list **stack, char *src);
int		push(t_list **stack1, t_list **stack2, char *src);

t_list	*findmin(t_list *stack);
int		check_order(t_list *stack, char c, int n);

int		ft_atoistrong(const char *str);
int		ft_bigger(t_list *stack1, t_list *stack2);
int		ft_smaller(t_list *stack1, t_list *stack2);
int		ft_biggernb(t_list *stack1, int n);
int		ft_smallernb(t_list *stack1, int n);

int		ft_ini(int argc, char **argv, t_list **stack_a, t_op *analysis);
t_list	*fill_list(int nbn, char **nb);
t_list	*ft_splittolst(char *str);
int		checkarg(t_list *stack);
int		checkintminmax(t_list *stack);
void	print_stack(t_list *stack_a, t_list *stack_b);

int		swap_or_not(t_list **stack_a, t_list **stack_b);
int		rotate_push(t_list **stack_a, t_list **stack_b, int L, int n);
int		rotate_swap(t_list **stack_a, t_list **stack_b);

int		smallsort(t_list **stack_a, t_list **stack_b, int L);
int		minisort(t_list **stack_a);
void	pushback(t_list **stack_a, t_list **stack_b, int n);

int		firstsort(t_list **stack_a, t_list **stack_b, int L, int n);
//int		checkendsort(t_list *stack);
int		sortback(t_list **stack_a, t_list **stack_b, int n);
int		revrotsort(t_list **stack_a, t_list **stack_b, int op);
void	backsort(t_list **stack_a, t_list **stack_b, int op);

#endif
