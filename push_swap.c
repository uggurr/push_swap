/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguyildi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:58:54 by uguyildi          #+#    #+#             */
/*   Updated: 2023/01/17 15:58:57 by uguyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	number_check(t_stack *heap)
{
	if (heap->size == 2)
		two_swap(heap);
	else if (heap->size == 3)
		three_swap(heap);
	else if (heap->size < 6)
		four_swap(heap);
	else if (heap->size >= 6)
	{
		find_maxbit(heap);
		radix(heap);
	}
}

void	repeat_check(t_stack *heap)
{
	int	i;
	int	j;

	i = 0;
	while (i < heap->size - 1)
	{
		j = i + 1;
		while (j < heap->size)
		{
			if (heap->sa[i] == heap->sa[j])
			{
				write (2, "Error\n", 6);
				all_free(heap);
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

	i = 0;
	while (i < heap->size - 1)
	{
		if (heap->sa[i] > heap->sa[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	ft_directory(t_stack *heap)
{
	repeat_check(heap);
	if ((sorted_check(heap) == 1))
	{
		all_free(heap);
		exit (0);
	}
	sorted_list(heap);
	buble_sort(heap);
	number_check(heap);
	all_free(heap);
}

int	main(int ag, char **av)
{
	t_stack	*heap;

	if (ag > 1)
	{
		heap = (t_stack *)malloc(sizeof(t_stack));
		heap->size = get_count(av);
		if (heap->size == 0)
		{
			write(2, "Erorr\n", 6);
			free(heap);
			return (0);
		}
		heap->sa = (int *)malloc(sizeof(int) * heap->size);
		heap->ssort = (int *)malloc(sizeof(int) * heap->size);
		heap->sb = (int *)malloc(sizeof(int) * heap->size);
		get_arg(heap, av);
		ft_directory(heap);
	}
	else
		return (0);
}
