#include "push_swap.h"

t_stack	*copy_lst(t_stack *stack_a, t_stack *stack_c)
{
	t_lst_ps *temp;
	t_lst_ps *temp2;

	temp = stack_a->head;
	while (temp != NULL)
	{
		if (!stack_c->head)
			stack_c->head = ft_lstnew_double(temp->nb);
		else
		{
			temp2 = ft_lstnew_double(temp->nb);
			ft_lstadd_back_double(&stack_c->head, temp2, stack_c);
		}
		temp = temp->next;
	}
	return (stack_c);
}

void ft_swap(t_lst_ps **lst)
{
	int i;
	int j;

	if (*lst && (*lst)->next)
	{
		i = (*lst)->nb;
		j = (*lst)->next->nb;
		(*lst)->nb = j;
		(*lst)->next->nb = i;
	}
}

void	bubblesort(t_stack *stack_c)
{
	t_lst_ps *temp;

	temp = stack_c->head ;
	while (temp && temp->next)
	{
		if (temp->nb > temp->next->nb)
		{
			ft_swap(&temp);
			temp = stack_c->head;
		}
		else
			temp = temp->next;
	}
}

void fill_key_values(t_stack *stack_a, t_stack *stack_c)
{
	int i;
	t_lst_ps *temp_c;
	t_lst_ps *temp_a;

	i = 1;
	temp_c = stack_c->head;
	while (temp_c)
	{
		temp_c->key = i;
		i++;
		temp_c = temp_c->next;
	}
	temp_a = stack_a->head;
	while (temp_a)
	{
		temp_c = stack_c->head;
		while(temp_a->nb != temp_c->nb && temp_c)
			temp_c = temp_c->next;
		temp_a->key = temp_c->key;
		temp_a = temp_a->next;
	}
}

int	check_sorted(t_stack *stack_a)
{
	t_lst_ps *temp;

	temp = stack_a->head;
	while (temp && temp->next)
	{
		if (temp->nb >= temp->next->nb)
			return (0);
		temp = temp->next;
	}
	return (1);
}


void radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int i;
	int j;
	int num;
	t_lst_ps *temp;

	i = 0;
	while (!check_sorted(stack_a))
	{
		temp = stack_a->head;
		j = lstsize(stack_a->head);
		while (j > 0)
		{
			num = temp->key;
			temp = temp->next;
			if((num >> i) & 1)
				ft_ra(stack_a, stack_b, 1);
			else
				ft_pb(stack_a, stack_b);
			j--;
		}
		i++;
		while (stack_b->head)
			ft_pa(stack_a, stack_b);
	}
}