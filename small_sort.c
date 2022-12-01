/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrainpre <jrainpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:25:16 by jrainpre          #+#    #+#             */
/*   Updated: 2022/12/01 13:49:29 by jrainpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->last = ft_lstlast_double(stack_a->head);
	if (stack_a->head->next->nb < stack_a->head->nb && \
		stack_a->head->next->nb < stack_a->last->nb && \
		stack_a->head->nb < stack_a->last->nb)
		ft_sa(stack_a, stack_b, 1);
	else if (stack_a->head->nb > stack_a->head->next->nb && \
				stack_a->head->next->nb > stack_a->last->nb)
	{
		ft_sa(stack_a, stack_b, 1);
		ft_rra(stack_a, stack_b, 1);
	}
	else if (stack_a->head->next->nb < stack_a->head->nb && \
				stack_a->head->next->nb < stack_a->last->nb && \
				stack_a->head->nb > stack_a->last->nb)
		ft_ra(stack_a, stack_b, 1);
	else if (stack_a->head->next->nb > stack_a->head->nb && \
				stack_a->head->next->nb > stack_a->last->nb && \
				stack_a->head->nb < stack_a->last->nb)
	{
		ft_sa(stack_a, stack_b, 1);
		ft_ra(stack_a, stack_b, 1);
	}
	else
		ft_rra(stack_a, stack_b, 1);
}

void	rotate_small_top(t_stack *stack, t_lst_ps *smallest)
{
	while (stack->head != smallest)
		ft_ra(stack, NULL, 1);
}

void	ft_sort_four(t_stack *stack_a, t_stack *stack_b)
{
	rotate_small_top(stack_a, ft_find_smallest(stack_a));
	if (!check_sorted(stack_a))
	{
		ft_pb(stack_a, stack_b);
		ft_sort_three(stack_a, stack_b);
		ft_pa(stack_a, stack_b);
	}
}

void	ft_sort_five(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_find_smallest(stack_a) == stack_a->last)
		ft_rra(stack_a, stack_b, 1);
	rotate_small_top(stack_a, ft_find_smallest(stack_a));
	if (!check_sorted(stack_a))
		ft_pb(stack_a, stack_b);
	ft_sort_four(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}

void	sort(t_stack *stack_a, t_stack *stack_b, t_stack *stack_c)
{
	int	size;

	size = lstsize(stack_a->head);
	if (size < 2 || check_sorted(stack_a))
		return ;
	if (size == 2)
		rotate_small_top(stack_a, ft_find_smallest(stack_a));
	if (size == 3)
		ft_sort_three(stack_a, stack_b);
	if (size == 4)
		ft_sort_four(stack_a, stack_b);
	if (size == 5)
		ft_sort_five(stack_a, stack_b);
	if (size > 5)
	{
		stack_c = copy_lst(stack_a, stack_c);
		bubblesort(stack_c);
		fill_key_values(stack_a, stack_c);
		radix_sort(stack_a, stack_b);
		free_lst_ps(stack_c);
	}
}
