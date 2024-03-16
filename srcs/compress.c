#include "push_swap.h"

void compress_num(t_data *data)
{
    t_stack    *tmp;
    t_stack    *tmp2;

    tmp = data->stack_a;
    while (tmp)
    {
        tmp2 = data->stack_a;
        while (tmp2)
        {
            if (tmp->original > tmp2->original)
                tmp->index++;
            tmp2 = tmp2->next;
        }
        tmp = tmp->next;
    }
}
