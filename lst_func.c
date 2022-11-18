#include "push_swap.h"

t_lst_ps	*ft_lstlast_double(t_lst_ps *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

t_lst_ps	*ft_lstnew_double(int	content)
{
	t_lst_ps	*entry;

	entry = (t_lst_ps *)malloc(sizeof(t_lst_ps));
	if (!entry)
		return (NULL);
	entry->prev = NULL;
	entry->next = NULL;
	entry->nb = content;
	return (entry);
}

void	ft_lstadd_back_double(t_lst_ps **lst, t_lst_ps *new, t_deque *deque)
{
	t_lst_ps	*prevlast;

	if (deque->head == NULL)
			{
		*lst = new;
		deque->head = new;
		deque->last = new;
	}
	else if (*lst)
	{
		prevlast = ft_lstlast_double(*lst);
		prevlast->next = new;
		new->prev = prevlast;
		deque->last = new;
	}
}

void	free_lst_ps(t_deque *deque)
{
	t_lst_ps *current;
	t_lst_ps *next;

	current = deque->head;
	while(current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

int	ft_contains_space(char *str)
{	
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' || str[i] == '\t' || str[i] == '\v' \
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
			return (1);
			i++;
	}
	return (0);
}