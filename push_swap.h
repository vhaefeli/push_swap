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
int		ft_lstsize(t_list *lst);
t_list	*ft_lstnew2(void *content);
void	ft_lstadd_front(t_list **alst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*fill_list(int nbn, char **nb);

void	swap(t_list **stack);
void	rotate(t_list **stack);
void	rev_rotate(t_list **stack);
void	push(t_list **stack1, t_list **stack2);

#endif
