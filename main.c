/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrainpre <jrainpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:25:41 by jrainpre          #+#    #+#             */
/*   Updated: 2022/12/01 14:05:03 by jrainpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		stack_a;
	t_stack		stack_b;
	t_stack		stack_c;

	if (argc < 2)
		free_error_message(NULL, NULL, NULL);
	stack_a.head = NULL;
	stack_a.last = NULL;
	stack_b.head = NULL;
	stack_b.last = NULL;
	stack_c.head = NULL;
	stack_c.last = NULL;
	take_mixed(argv, &stack_a);
	if (!check_doubles(&stack_a))
		free_error_message(&stack_a, NULL, NULL);
	sort(&stack_a, &stack_b, &stack_c);
	free_lst_ps(&stack_a);
}
