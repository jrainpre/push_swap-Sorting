
#include "push_swap.h"

// void    take_str(int argc, char **argv, t_deque *deque)
// {
//     t_lst_ps    *temp;
//     char        **nbrs;
//     int         i;


//     nbrs = ft_split(argv[1], ' ');
//     deque->head = ft_lstnew_double(atoi(nbrs[0]));
//     i = 1;
//     while(nbrs[i])
//     {
// 		temp = ft_lstnew_double(atoi(nbrs[i]));
// 		ft_lstadd_back_double(&deque->head, temp, deque);
// 		i++;
//     }
//     i = 0;
//     while(nbrs[i])
//     {
//         free(nbrs[i]);
// 		i++;
//     }
//     free(nbrs);
// }

// void    take_args(int argc, char **argv, t_deque *deque)
// {

//     t_lst_ps    *temp;
//     int         i;
//     deque->head = ft_lstnew_double(atoi(argv[1]));
// 	i = 2;
// 	while(i < argc)
// 	{
// 		temp = ft_lstnew_double(atoi(argv[i]));
// 		ft_lstadd_back_double(&deque->head, temp, deque);
// 		i++;
// 	}
// }

void    take_strarg(char *argv, t_deque *deque)
{
    t_lst_ps    *temp;
    char        **nbrs;
    int         i;

    nbrs = ft_split(argv, ' ');
    if (!deque->head)
        deque->head = ft_lstnew_double(atoi(nbrs[0]));
    i = 1;
    while(nbrs[i])
    {
		temp = ft_lstnew_double(atoi(nbrs[i]));
		ft_lstadd_back_double(&deque->head, temp, deque);
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


void    take_mixed(int argc, char **argv, t_deque *deque)
{
    int         i;
    t_lst_ps    *temp;

    i = 1;
    while(argv[i])
    {
        if (ft_contains_space(argv[i]))
            take_strarg(argv[i], deque);
        else
            {
                if (!deque->head)
                    deque->head = ft_lstnew_double(atoi(argv[i]));
                    else
                  temp = ft_lstnew_double(atoi(argv[i]));
		        ft_lstadd_back_double(&deque->head, temp, deque);

            }
        i++;
    }
}