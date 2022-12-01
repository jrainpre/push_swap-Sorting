/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrainpre <jrainpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:25:21 by jrainpre          #+#    #+#             */
/*   Updated: 2022/12/01 13:50:33 by jrainpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*copy_lst(t_stack *stack_a, t_stack *stack_c)
{
	t_lst_ps	*temp;
	t_lst_ps	*temp2;

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

void	ft_swap(t_lst_ps **lst)
{
	int	i;
	int	j;

	if (*lst && (*lst)->next)
	{
		i = (*lst)->nb;
		j = (*lst)->next->nb;
		(*lst)->nb = j;
		(*lst)->next->nb = i;
	}
}

void	fill_key_values(t_stack *stack_a, t_stack *stack_c)
{
	int			i;
	t_lst_ps	*temp_c;
	t_lst_ps	*temp_a;

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
		while (temp_a->nb != temp_c->nb && temp_c)
			temp_c = temp_c->next;
		temp_a->key = temp_c->key;
		temp_a = temp_a->next;
	}
}

int	check_sorted(t_stack *stack_a)
{
	t_lst_ps	*temp;

	temp = stack_a->head;
	while (temp && temp->next)
	{
		if (temp->nb >= temp->next->nb)
			return (0);
		temp = temp->next;
	}
	return (1);
}

t_lst_ps	*ft_find_smallest(t_stack *stack)
{
	t_lst_ps	*smol;
	t_lst_ps	*temp;

	smol = stack->head;
	temp = stack->head->next;
	while (temp != NULL)
	{
		if (temp->nb < smol->nb)
			smol = temp;
		temp = temp->next;
	}
	return (smol);
}
