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

t_list	*ft_lstnew2(char *src);
void	lst_del(t_list **stack);

void	ft_findposition(t_list **stack);
int		ft_bestpartition(t_list *stack);


void	swap(t_list **stack);
void	rotate(t_list **stack);
void	rev_rotate(t_list **stack);
void	push(t_list **stack1, t_list **stack2);

t_list	*findmin(t_list *stack);
int		check_order(t_list *stack, char c, int n);

int		ft_atoistrong(const char *str);
int		ft_bigger(t_list *stack1, t_list *stack2);
int		ft_smaller(t_list *stack1, t_list *stack2);
int		ft_biggernb(t_list *stack1, int n);
int		ft_smallernb(t_list *stack1, int n);

t_list	*fill_list(int nbn, char **nb);
t_list	*ft_splittolst(char *str);
int		checkarg(t_list *stack);
int		checkintminmax(t_list *stack);
void	print_stack(t_list *stackA, t_list *stackB);

void	swap_or_not(t_list **stackA, t_list **stackB);
int		swap_or_not2(t_list **stackA, t_list **stackB);
int		rotate_pushAB(t_list **stackA, t_list **stackB, int L, int n);
int		rotate_pushBA(t_list **stackA, t_list **stackB, int n);
int		rotate_swap(t_list **stackA, t_list **stackB);

int 	smallsortA(t_list **stackA, t_list **stackB, int L);
int 	minisortA(t_list **stackA);
int 	smallsortB(t_list **stackA, t_list **stackB, int L);
int 	minisortB(t_list **stackA);
void	pushback(t_list **stackA, t_list **stackB, int n);

int		firstsortAB(t_list **stackA, t_list **stackB, int L, int n);
int     checkendsort(t_list *stack);
int		firstsortBA(t_list **stackA, t_list **stackB);
int		secondsort(t_list **stackA, t_list **stackB, int op);
int		sortback(t_list **stackA, t_list **stackB, int n);
int		revrotsort(t_list **stackA, t_list **stackB, int op);

#endif
