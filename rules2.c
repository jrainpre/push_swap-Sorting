/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrainpre <jrainpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:23:43 by jrainpre          #+#    #+#             */
/*   Updated: 2022/12/01 13:47:17 by jrainpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack *stack_a, t_stack *stack_b, int print)
{
	t_lst_ps	*temp;

	(void)stack_b;
	if (!(stack_a->head && stack_a->head->next))
		return ;
	temp = stack_a->head;
	stack_a->head = stack_a->head->next;
	stack_a->head->prev = NULL;
	temp->next = NULL;
	ft_lstadd_back_double(&stack_a->head, temp, stack_a);
	if (print)
		ft_printf("ra\n");
	return ;
}

void	ft_rb(t_stack *stack_a, t_stack *stack_b, int print)
{
	t_lst_ps	*temp;

	(void)stack_a;
	if (!(stack_b->head && stack_b->head->next))
		return ;
	temp = stack_b->head;
	stack_b->head = stack_b->head->next;
	stack_b->head->prev = NULL;
	temp->next = NULL;
	ft_lstadd_back_double(&stack_b->head, temp, stack_b);
	if (print)
		ft_printf("ra\n");
	return ;
}

void	ft_rr(t_stack *stack_a, t_stack *stack_b)
{
	ft_ra(stack_a, stack_b, 0);
	ft_rb(stack_a, stack_b, 0);
}
