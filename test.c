
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	t_deque deque_a;
	t_deque deque_b;
	t_lst_ps *temp;
	
	deque_a.head = NULL;
	deque_a.last = NULL;
	deque_b.head = NULL;
	deque_b.last = NULL;
	take_mixed(argc, argv, &deque_a);
	// ft_sa(&deque_a, &deque_b);
	ft_pb(&deque_a, &deque_b);
	ft_pb(&deque_a, &deque_b);
	ft_sa(&deque_a, &deque_b);
	ft_ra(&deque_a, &deque_b);
	ft_pa(&deque_a, &deque_b);
	ft_ra(&deque_a, &deque_b);
	ft_pa(&deque_a, &deque_b);
	temp = deque_a.head;
	while (temp)
	{
		printf("%d\n", temp->nb);
		temp = temp->next;
	}
	free_lst_ps(&deque_a);
	printf("%s\n", "stack b");
	temp = deque_b.head;
	while (temp)
	{
		printf("%d\n", temp->nb);
		temp = temp->next;
	}
	free_lst_ps(&deque_b);
}


void ft_sort_three()