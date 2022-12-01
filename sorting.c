/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrainpre <jrainpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:25:25 by jrainpre          #+#    #+#             */
/*   Updated: 2022/12/01 13:51:04 by jrainpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubblesort(t_stack *stack_c)
{
	t_lst_ps	*temp;

	temp = stack_c->head;
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

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int			i;
	int			j;
	int			num;
	t_lst_ps	*temp;

	i = 0;
	while (!check_sorted(stack_a))
	{
		temp = stack_a->head;
		j = lstsize(stack_a->head);
		while (j > 0)
		{
			num = temp->key;
			temp = temp->next;
			if ((num >> i) & 1)
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
