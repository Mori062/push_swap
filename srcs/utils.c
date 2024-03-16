#include "push_swap.h"

void	*xmalloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		exit(1);
	return (ptr);
}

int	error_exit(void)
{
	write(2, "Error\n", 6);
	return (1);
}