
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>



int main (int argc, char **argv)
{
	if(argc < 3)
		return (0);
	int		i;
	t_lst_ps	*temp;
	t_deque deque;
	deque.head = NULL;
	deque.last = NULL;
	deque.head = ft_lstnew_double(atoi(argv[1]));
	i = 2;
	while(i < argc)
	{
		temp = ft_lstnew_double(atoi(argv[i]));
		ft_lstadd_back_double(&deque.head, temp, &deque);
		i++;
	}
	  ft_lst_swap(&deque.head, &deque);
	temp = deque.head;
	while (temp)
	{
		printf("%d\n", temp->nb);
		temp = temp->next;
	}
}


