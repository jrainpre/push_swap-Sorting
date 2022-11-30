
#include "push_swap.h"

void    take_strarg(char *argv, t_stack *stack)
{
    t_lst_ps    *temp;
    char        **nbrs;
    int         i;
     i = 0;
    nbrs = ft_split(argv, ' ');
    if (!stack->head)
        stack->head = ft_lstnew_double(atoi(nbrs[i++]));
    while(nbrs[i])
    {
		temp = ft_lstnew_double(atoi(nbrs[i]));
		ft_lstadd_back_double(&stack->head, temp, stack);
		i++;
    }
    i = 0;
    while(nbrs[i])
    {
        free(nbrs[i]);
		i++;
    }
    free(nbrs);
}

void    take_mixed(int argc, char **argv, t_stack *stack)
{
    int         i;
    t_lst_ps    *temp;

    i = 1;
    while(argv[i])
    {
        if (ft_contains_space(argv[i]))
            take_strarg(argv[i], stack);
        else
            {
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