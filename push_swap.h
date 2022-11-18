#ifndef SWAP_H
# define SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_list_ps
{
	int			nb;
	struct s_list_ps	*prev;
	struct s_list_ps	*next;
}t_lst_ps;

typedef struct s_deque
{
	struct s_list_ps	*head;
	struct s_list_ps	*last;
}t_deque;

void	ft_lstadd_back_double(t_lst_ps **lst, t_lst_ps *new, t_deque *deque);
t_lst_ps	*ft_lstnew_double(int	content);
t_lst_ps	*ft_lstlast_double(t_lst_ps *lst);
t_lst_ps	*ft_lstnew_double(int	content);
void	ft_lst_swap(t_lst_ps **lst, t_deque *deque);

#endif
