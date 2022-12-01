/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrainpre <jrainpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:25:07 by jrainpre          #+#    #+#             */
/*   Updated: 2022/12/01 13:47:43 by jrainpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack *stack_a, t_stack *stack_b, int print)
{
	t_lst_ps	*temp;

	(void)stack_b;
	stack_a->last = ft_lstlast_double(stack_a->head);
	if (!(stack_a->head && stack_a->head->next))
		return ;
	temp = stack_a->last;
	stack_a->last = stack_a->last->prev;
	stack_a->last->next = NULL;
	ft_add_lstentry_first(stack_a, temp);
	if (print)
		ft_printf("rra\n");
	return ;
}

void	ft_rrb(t_stack *stack_a, t_stack *stack_b, int print)
{
	t_lst_ps	*temp;

	(void)stack_a;
	if (!(stack_b->head && stack_b->head->next))
		return ;
	temp = stack_b->last;
	stack_b->last = stack_b->last->prev;
	stack_b->last->next = NULL;
	ft_add_lstentry_first(stack_b, temp);
	if (print)
		ft_printf("rrb\n");
	return ;
}

void	ft_rrr(t_stack *stack_a, t_stack *stack_b)
{
	ft_rra(stack_a, stack_b, 0);
	ft_rrb(stack_a, stack_b, 0);
	ft_printf("rrr\n");
}
