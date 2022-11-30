#include "push_swap.h"


int	check_input(t_stack *stack)
{
	int result;

	result = check_doubles(stack);

}

int check_doubles(t_stack *stack)
{
	t_lst_ps *temp1;
	t_lst_ps *temp2;

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
