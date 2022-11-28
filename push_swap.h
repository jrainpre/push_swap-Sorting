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
void	free_lst_ps(t_deque *deque);
int		ft_contains_space(char *str);
void    take_strarg(char *argv, t_deque *deque);
void    take_mixed(int argc, char **argv, t_deque *deque);
void ft_add_lstentry_first(t_deque *deque, t_lst_ps *new);

int	ft_sa(t_deque *deque_a, t_deque *deque_b);
int ft_sb(t_deque *deque_a, t_deque *deque_b);
int ft_ss(t_deque *deque_a, t_deque *deque_b);
int ft_pa(t_deque *deque_a, t_deque *deque_b);
int ft_pb(t_deque *deque_a, t_deque *deque_b);
int ft_ra(t_deque *deque_a, t_deque *deque_b);
int ft_rb(t_deque *deque_a, t_deque *deque_b);
int ft_rr(t_deque *deque_a, t_deque *deque_b);
int ft_rra(t_deque *deque_a, t_deque *deque_b);
int ft_rrb(t_deque *deque_a, t_deque *deque_b);
int ft_rrr(t_deque *deque_a, t_deque *deque_b);


#endif
