#include "push_swap.h"
void	number_check(t_stack *heap)
{
	if (heap->size == 2)
		two_swap(heap);
}

void	repeat_check(t_stack *heap)
{
	int	i;
	int	j;

	i = 0;
	while (i < heap->size)
	{
		j = i + 1;
		while (j < heap->size)
		{
			if (heap->sa[i] == heap->sa[j])
			{
				write (2, "Error\n", 6);
				exit (0);
			}
			j++;
		}
		i++;
	}
}

int	sorted_check(t_stack *heap)
{
	int	i;
	int	flag;

	i = 0;
	while (i < heap->size - 1)
	{
		if (heap->sa[i] > heap->sa[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	all_free(t_stack *heap)
{
	free(heap->sa);
	free(heap->sb);
	free(heap);
}

int	main(int ag, char **av)
{
	t_stack	*heap;

	heap = (t_stack *)malloc(sizeof(t_stack));
	heap->size = get_count(av);
	if (heap->size == 0)
	{
		free(heap);
		return (0);
	}
	heap->sa = (int *)malloc(sizeof(int) * heap->size);
	heap->sb = (int *)malloc(sizeof(int) * heap->size);
	get_arg(heap, av);
	repeat_check(heap);
	if ((sorted_check(heap) == 1))
	{
		all_free(heap);
		return (0);
	}
	number_check(heap);
}
