
#include "push_swap.h"


int	main(int argc, char **argv)
{
	t_stack		stack_a;
	t_stack		stack_b;
	t_stack		stack_c;
	t_lst_ps	*temp;

	stack_a.head = NULL;
	stack_a.last = NULL;
	stack_b.head = NULL;
	stack_b.last = NULL;
	stack_c.head = NULL;
	stack_c.last = NULL;
	take_mixed(argc, argv, &stack_a);
	sort(&stack_a, &stack_b, &stack_c);
	// printf("%s\n", "stack a");
	temp = stack_a.head;
	// while (temp)
	// {
	// 	printf("%d\n", temp->nb);
	// 	temp = temp->next;
	// }
	// free_lst_ps(&stack_a);
	// printf("%s\n", "stack b");
	temp = stack_b.head;
	// while (temp)
	// {
	// 	printf("%d\n", temp->nb);
	// 	temp = temp->next;
	// }
	free_lst_ps(&stack_b);
}
