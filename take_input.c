/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrainpre <jrainpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:25:33 by jrainpre          #+#    #+#             */
/*   Updated: 2022/12/01 13:53:25 by jrainpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_number_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] == '+' || str[i] == '-' || ft_isdigit(str[i])))
			return (0);
		i++;
	}
	if (ft_atoi(str) == -1)
	{
		if (ft_strncmp("-1", str, 2) != 0)
			return (0);
	}
	return (1);
}

void	take_strarg(char *argv, t_stack *stack)
{
	t_lst_ps	*temp;
	char		**nbrs;
	int			i;

	i = 0;
	nbrs = ft_split(argv, ' ');
	if (!check_number_valid(nbrs[i]))
		free_error_message(stack, NULL, NULL);
	if (!stack->head)
		stack->head = ft_lstnew_double(atoi(nbrs[i++]));
	while (nbrs[i])
	{
		if (!check_number_valid(nbrs[i]))
			free_error_message(stack, NULL, NULL);
		temp = ft_lstnew_double(atoi(nbrs[i]));
		ft_lstadd_back_double(&stack->head, temp, stack);
		i++;
	}
	i = 0;
	while (nbrs[i])
	{
		free(nbrs[i]);
		i++;
	}
	free(nbrs);
}

void	take_mixed(char **argv, t_stack *stack)
{
	int			i;
	t_lst_ps	*temp;

	i = 1;
	while (argv[i])
	{
		if (ft_contains_space(argv[i]))
			take_strarg(argv[i], stack);
		else
		{
			if (!check_number_valid(argv[i]))
				free_error_message(stack, NULL, NULL);
			if (!stack->head)
				stack->head = ft_lstnew_double(atoi(argv[i]));
			else
			{
				temp = ft_lstnew_double(atoi(argv[i]));
				ft_lstadd_back_double(&stack->head, temp, stack);
			}
		}
		i++;
	}
}

void	free_error_message(t_stack *a, t_stack *b, t_stack *c)
{
	free_lst_ps(a);
	free_lst_ps(b);
	free_lst_ps(c);
	ft_printf("%s\n", "Error");
	exit(0);
}

int	check_doubles(t_stack *stack)
{
	t_lst_ps	*temp1;
	t_lst_ps	*temp2;

	if (stack->head != NULL)
	{
		temp1 = stack->head;
		while (temp1 && temp1->next)
		{
			temp2 = temp1->next;
			while (temp2)
			{
				if (temp1->nb == temp2->nb)
					return (0);
				temp2 = temp2->next;
			}
			temp1 = temp1->next;
		}
	}
	return (1);
}
