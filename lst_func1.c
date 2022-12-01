/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrainpre <jrainpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:24:02 by jrainpre          #+#    #+#             */
/*   Updated: 2022/12/01 13:41:19 by jrainpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

t_lst_ps	*ft_lstnew_double(int content)
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

void	ft_lstadd_back_double(t_lst_ps **lst, t_lst_ps *new, t_stack *stack)
{
	t_lst_ps	*prevlast;

	if (stack->head == NULL)
	{
		*lst = new;
		stack->head = new;
		stack->last = new;
	}
	else if (*lst)
	{
		prevlast = ft_lstlast_double(*lst);
		prevlast->next = new;
		new->prev = prevlast;
		stack->last = new;
	}
}

void	ft_add_lstentry_first(t_stack *stack, t_lst_ps *new)
{
	if (stack->head == NULL)
	{
		stack->head = new;
		stack->last = new;
	}
	else
	{
		stack->head->prev = new;
		new->next = stack->head;
		stack->head = new;
	}
}

void	free_lst_ps(t_stack *stack)
{
	t_lst_ps	*current;
	t_lst_ps	*next;

	if (stack != NULL)
	{
		current = stack->head;
		while (current)
		{
			next = current->next;
			free(current);
			current = next;
		}
	}
}
