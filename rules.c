
#include "push_swap.h"

int	ft_sa(t_deque *deque_a, t_deque *deque_b)
{
	t_lst_ps *temp;
	deque_a->last = ft_lstlast_double(deque_a->head);
	if (!(deque_a->head && deque_a->head->next))
		return (0);
	temp = deque_a->head;
	deque_a->head = temp->next;
	deque_a->head->prev = NULL;
	temp->next = deque_a->head->next;
	deque_a->head->next = temp;
	temp->prev = deque_a->head;
	deque_a->last = ft_lstlast_double(deque_a->head);
	if (deque_a->head->next != deque_a->last)
		deque_a->head->next->next->prev = deque_a->head->next;
	return (1);
}

int ft_sb(t_deque *deque_a, t_deque *deque_b)
{
	t_lst_ps *temp;
	deque_b->last = ft_lstlast_double(deque_b->head);
	if (!(deque_b->head && deque_b->head->next))
		return (0);
	temp = deque_b->head;
	deque_b->head = temp->next;
	deque_b->head->prev = NULL;
	temp->next = deque_b->head->next;
	deque_b->head->next = temp;
	temp->prev = deque_b->head;
	deque_b->last = ft_lstlast_double(deque_b->head);
	if (deque_b->head->next != deque_b->last)
		deque_b->head->next->next->prev = deque_b->head->next;
	return (1);
}

int ft_ss(t_deque *deque_a, t_deque *deque_b)
{
	ft_sa(deque_a, deque_b);
	ft_sb(deque_a, deque_b);
}

int ft_pa(t_deque *deque_a, t_deque *deque_b)
{
	t_lst_ps *temp;
	if (!deque_b->head)
		return (0);
		if (deque_a->head == NULL)
		{
			temp = deque_b->head;
			deque_a->head = temp;
			deque_b->head = deque_b->head->next;
			deque_b->head->prev = NULL;
			deque_a->head->prev = NULL;
			deque_a->head->next = NULL;
		} else
		{
			temp = deque_a->head;
			deque_a->head = deque_b->head;
			deque_b->head = deque_b->head->next;
			if (deque_b->head)
				deque_b->head->prev = NULL;
			deque_a->head->prev = NULL;
			deque_a->head->next = temp;
			deque_a->head->next->prev = deque_a->head;
		}
	return (1);
}

int ft_pb(t_deque *deque_a, t_deque *deque_b)
{
	t_lst_ps *temp;
	if (!deque_a->head)
		return (0);
		if (deque_b->head == NULL)
		{
			temp = deque_a->head;
			deque_b->head = temp;
			deque_a->head = deque_a->head->next;
			deque_a->head->prev = NULL;
			deque_b->head->prev = NULL;
			deque_b->head->next = NULL;
		} else
		{
			temp = deque_b->head;
			deque_b->head = deque_a->head;
			deque_a->head = deque_a->head->next;
			if (deque_a->head)
				deque_a->head->prev = NULL;
			deque_b->head->prev = NULL;
			deque_b->head->next = temp;
			deque_b->head->next->prev = deque_b->head;
		}
	return (1);
}

int ft_ra(t_deque *deque_a, t_deque *deque_b)
{
	t_lst_ps *temp;

	if (!(deque_a->head && deque_a->head->next))
		return (0);
	temp = deque_a->head;
	deque_a->head = deque_a->head->next;
	deque_a->head->prev = NULL;
	temp->next = NULL;
	ft_lstadd_back_double(&deque_a->head, temp, deque_a);
	return (1);
}

int ft_rb(t_deque *deque_a, t_deque *deque_b)
{
	t_lst_ps *temp;

	if (!(deque_b->head && deque_b->head->next))
		return (0);
	temp = deque_b->head;
	deque_b->head = deque_b->head->next;
	deque_b->head->prev = NULL;
	temp->next = NULL;
	ft_lstadd_back_double(&deque_b->head, temp, deque_b);
	return (1);
}

int ft_rr(t_deque *deque_a, t_deque *deque_b)
{
	ft_ra(deque_a, deque_b);
	ft_rb(deque_a, deque_b);
}

int ft_rra(t_deque *deque_a, t_deque *deque_b)
{
	t_lst_ps *temp;

	deque_a->last = ft_lstlast_double(deque_a->head);
	if (!(deque_a->head && deque_a->head->next))
		return (0);
	temp = deque_a->last;
	deque_a->last = deque_a->last->prev;
	deque_a->last->next = NULL;
	// temp->prev = NULL;
	ft_add_lstentry_first(deque_a, temp);
	return (1);
}

int ft_rrb(t_deque *deque_a, t_deque *deque_b)
{
	t_lst_ps *temp;

	if (!(deque_b->head && deque_b->head->next))
		return (0);
	temp = deque_b->last;
	deque_b->last = deque_b->last->prev;
	deque_b->last->next = NULL;
	temp->prev = NULL;
	ft_add_lstentry_first(deque_b, temp);
	return (1);
}

int ft_rrr(t_deque *deque_a, t_deque *deque_b)
{
	ft_rra(deque_a, deque_b);
	ft_rrb(deque_a, deque_b);
}