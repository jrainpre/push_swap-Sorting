# include "push_swap.h"

// swap to list entries
void	ft_lst_swap(t_lst_ps **lst, t_stack *stack)
{
	t_lst_ps	*temp;
	int i;

	i = 0;
	if (*lst && (*lst)->next)
	{
		if (*lst == stack->head)
			i = 1;
		if ((*lst)->next == stack->last)
			stack->last =*lst;			
		temp = (*lst)->next;
		(*lst)->next = temp->next;
		temp->next = *lst;
		*lst = temp;
		if (i == 1)
			stack->head = *lst;
	}
}