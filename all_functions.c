#include "push_swap.h"

void	sa(t_stack *heap)
{
	int	tmp;

	tmp = heap->sa[0];
	heap->sa[0] = heap->sa[1];
	heap->sa[1] = tmp;
	write(1,"sa\n",3);
}
