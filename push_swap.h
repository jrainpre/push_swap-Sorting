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

void	ft_lstadd_back_double(t_lst_ps **lst, t_lst_ps *new);
t_lst_ps	*ft_lstnew_double(int	content);
t_lst_ps	*ft_lstlast_double(t_list *lst);

#endif