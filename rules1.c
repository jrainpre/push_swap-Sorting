/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrainpre <jrainpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:25:00 by jrainpre          #+#    #+#             */
/*   Updated: 2022/12/01 13:46:54 by jrainpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *stack_a, t_stack *stack_b, int print)
{
	t_lst_ps	*temp;

	(void)stack_b;
	stack_a->last = ft_lstlast_double(stack_a->head);
	if (!(stack_a->head && stack_a->head->next))
		return ;
	temp = stack_a->head;
	stack_a->head = temp->next;
	stack_a->head->prev = NULL;
	temp->next = stack_a->head->next;
	stack_a->head->next = temp;
	temp->prev = stack_a->head;
	stack_a->last = ft_lstlast_double(stack_a->head);
	if (stack_a->head->next != stack_a->last)
		stack_a->head->next->next->prev = stack_a->head->next;
	if (print)
		ft_printf("sa\n");
	return ;
}

void	ft_sb(t_stack *stack_a, t_stack *stack_b, int print)
{
	t_lst_ps	*temp;

	(void)stack_a;
	stack_b->last = ft_lstlast_double(stack_b->head);
	if (!(stack_b->head && stack_b->head->next))
		return ;
	temp = stack_b->head;
	stack_b->head = temp->next;
	stack_b->head->prev = NULL;
	temp->next = stack_b->head->next;
	stack_b->head->next = temp;
	temp->prev = stack_b->head;
	stack_b->last = ft_lstlast_double(stack_b->head);
	if (stack_b->head->next != stack_b->last)
		stack_b->head->next->next->prev = stack_b->head->next;
	if (print)
		ft_printf("sb\n");
	return ;
}

void	ft_ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_sa(stack_a, stack_b, 0);
	ft_sb(stack_a, stack_b, 0);
	ft_printf("ss\n");
}

void	ft_pa(t_stack *stack_a, t_stack *stack_b)
{
	t_lst_ps	*temp;

	if (!stack_b->head)
		return ;
	if (stack_a->head == NULL)
	{
		temp = stack_b->head;
		stack_a->head = temp;
		stack_b->head = stack_b->head->next;
		stack_b->head->prev = NULL;
		stack_a->head->prev = NULL;
		stack_a->head->next = NULL;
	}
	else
	{
		temp = stack_a->head;
		stack_a->head = stack_b->head;
		stack_b->head = stack_b->head->next;
		if (stack_b->head)
			stack_b->head->prev = NULL;
		stack_a->head->prev = NULL;
		stack_a->head->next = temp;
		stack_a->head->next->prev = stack_a->head;
	}
	ft_printf("pa\n");
}

void	ft_pb(t_stack *stack_a, t_stack *stack_b)
{
	t_lst_ps	*temp;

	if (!stack_a->head)
		return ;
	if (stack_b->head == NULL)
	{
		temp = stack_a->head;
		stack_b->head = temp;
		stack_a->head = stack_a->head->next;
		stack_a->head->prev = NULL;
		stack_b->head->prev = NULL;
		stack_b->head->next = NULL;
	}
	else
	{
		temp = stack_b->head;
		stack_b->head = stack_a->head;
		stack_a->head = stack_a->head->next;
		if (stack_a->head)
			stack_a->head->prev = NULL;
		stack_b->head->prev = NULL;
		stack_b->head->next = temp;
		stack_b->head->next->prev = stack_b->head;
	}
	ft_printf("pb\n");
}
