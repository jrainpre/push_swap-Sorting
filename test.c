
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>



// int main (int argc, char **argv)
// {
// 	if(argc < 3)
// 		return (0);
// 	int		i;
// 	t_lst_ps	*temp;
// 	t_deque deque;
// 	deque.head = NULL;
// 	deque.last = NULL;
// 	deque.head = ft_lstnew_double(atoi(argv[1]));
// 	i = 2;
// 	while(i < argc)
// 	{
// 		temp = ft_lstnew_double(atoi(argv[i]));
// 		ft_lstadd_back_double(&deque.head, temp, &deque);
// 		i++;
// 	}
// 	  ft_lst_swap(&deque.head, &deque);
// 	temp = deque.head;
// 	while (temp)
// 	{
// 		printf("%d\n", temp->nb);
// 		temp = temp->next;
// 	}
// }

int main(int argc, char **argv)
{
	t_deque deque_a;
	t_lst_ps *temp;
	
	deque_a.head = NULL;
	deque_a.last = NULL;
	// if(argc == 2)
	// 	take_str(argc, argv, &deque_a);
	// if (argc > 2)
	// 	take_args(argc, argv, &deque_a);
		take_mixed(argc, argv, &deque_a);
	temp = deque_a.head;
	while (temp)
	{
		printf("%d\n", temp->nb);
		temp = temp->next;
	}
	free_lst_ps(&deque_a);
}


