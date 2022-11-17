
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>




int main (int argc, char **argv)
{
	if(argc < 3)
		return (0);
	t_list	*a;
	t_list	*b;
	int		i;
	t_list	*temp;

	a = ft_lstnew_double(atoi(argv[1]));
	i = 2;
	while(i < argc)
	{
		temp = ft_lstnew_double(atoi(argv[i]));
		ft_lstadd_back_double(&a, temp);
		i++;
	}
	printf("%d", ft_lstsize(a));
	while (a)
	{
		printf("%d", a->nb);
		a = a->next;
	}

}


