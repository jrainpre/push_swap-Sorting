/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrainpre <jrainpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:43:55 by jrainpre          #+#    #+#             */
/*   Updated: 2022/12/01 13:52:20 by jrainpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list_ps
{
	int					nb;
	int					key;
	struct s_list_ps	*prev;
	struct s_list_ps	*next;
}						t_lst_ps;

typedef struct s_stack
{
	struct s_list_ps	*head;
	struct s_list_ps	*last;
}						t_stack;

int						check_doubles(t_stack *stack);
t_lst_ps				*ft_lstlast_double(t_lst_ps *lst);
t_lst_ps				*ft_lstnew_double(int content);
void					ft_lstadd_back_double(t_lst_ps **lst, t_lst_ps *new,
							t_stack *stack);
void					ft_add_lstentry_first(t_stack *stack, t_lst_ps *new);
void					free_lst_ps(t_stack *stack);
int						ft_contains_space(char *str);
int						lstsize(t_lst_ps *lst);

void					ft_sa(t_stack *stack_a, t_stack *stack_b, int print);
void					ft_sb(t_stack *stack_a, t_stack *stack_b, int print);
void					ft_ss(t_stack *stack_a, t_stack *stack_b);
void					ft_pa(t_stack *stack_a, t_stack *stack_b);
void					ft_pb(t_stack *stack_a, t_stack *stack_b);
void					ft_ra(t_stack *stack_a, t_stack *stack_b, int print);
void					ft_rb(t_stack *stack_a, t_stack *stack_b, int print);
void					ft_rr(t_stack *stack_a, t_stack *stack_b);
void					ft_rra(t_stack *stack_a, t_stack *stack_b, int print);
void					ft_rrb(t_stack *stack_a, t_stack *stack_b, int print);
void					ft_rrr(t_stack *stack_a, t_stack *stack_b);

void					ft_sort_three(t_stack *stack_a, t_stack *stack_b);
t_lst_ps				*ft_find_smallest(t_stack *stack);
void					rotate_small_top(t_stack *stack, t_lst_ps *smallest);
void					ft_sort_four(t_stack *stack_a, t_stack *stack_b);
void					ft_sort_five(t_stack *stack_a, t_stack *stack_b);
void					sort(t_stack *stack_a, t_stack *stack_b,
							t_stack *stack_c);

t_stack					*copy_lst(t_stack *stack_a, t_stack *stack_c);
void					ft_swap(t_lst_ps **lst);
void					bubblesort(t_stack *stack_c);
void					fill_key_values(t_stack *stack_a, t_stack *stack_c);
int						check_sorted(t_stack *stack_a);
void					radix_sort(t_stack *stack_a, t_stack *stack_b);
void					ft_lst_swap(t_lst_ps **lst, t_stack *stack);

int						check_number_valid(char *str);
void					take_strarg(char *argv, t_stack *stack);
void					take_mixed(char **argv, t_stack *stack);
void					free_error_message(t_stack *a, t_stack *b, t_stack *c);

#endif
