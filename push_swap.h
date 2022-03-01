#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_list
{
	char			*content;
	int				nbr;
	struct	s_list	*next;
}					t_list;

int		ft_atoi(const char *str);
int		ft_bigger(t_list *stack1, t_list *stack2);
int		ft_smaller(t_list *stack1, t_list *stack2);
int		ft_biggernb(t_list *stack1, int n);
int		ft_smallernb(t_list *stack1, int n);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstnew2(void *content);
void	ft_lstadd_front(t_list **alst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	lst_del(t_list **stack);
t_list	*fill_list(int nbn, char **nb);

void	swap(t_list **stack);
void	rotate(t_list **stack);
void	rev_rotate(t_list **stack);
void	push(t_list **stack1, t_list **stack2);
void	printStack(t_list *stackA, t_list *stackB);
int		check_order(t_list *stack, char c, int n);
void	swap_or_not(t_list **stackA, t_list **stackB);
void	swap_or_not2(t_list **stackA, t_list **stackB);
int		middlevalue(t_list *stack);
int		rotate_pushAB(t_list **stackA, t_list **stackB, int n);
int		rotate_pushBA(t_list **stackA, t_list **stackB, int n);
void	pushback(t_list **stackA, t_list **stackB, int n);
int		firstsortAB(t_list **stackA, t_list **stackB);
int		firstsortBA(t_list **stackA, t_list **stackB);
int		secondsort(t_list **stackA, t_list **stackB, int op);

#endif
