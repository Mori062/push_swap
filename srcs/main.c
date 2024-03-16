#include "push_swap.h"

int main(int argc, char **argv)
{
    t_data		*data;
	t_result	*result;

    if (argc < 2)
        return (0);
    if (arg_invalid(argc, argv))
        return (error_exit());
    data = data_init();
	result = result_init();
    put_args_to_data(data, argc, argv);
    compress_num(data);
    if (is_sorted(data))
        return (0); // free_struct(data, result);
    sort_one(data, result);
	// sort_two(data, result);
	// sort_three(data, result);
    // free_data(data);
    return (0);
}