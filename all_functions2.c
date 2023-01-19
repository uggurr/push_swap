/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_functions2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguyildi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:57:16 by uguyildi          #+#    #+#             */
/*   Updated: 2023/01/17 15:57:21 by uguyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *heap)
{
	int	len;

	len = heap->size;
	towards_the_end(heap->sa, len);
	heap->sa[0] = heap->sb[0];
	towards_the_start(heap->sb, heap->bcount);
	heap->bcount--;
	heap->size++;
	write(1, "pa\n", 3);
}

void	rb(t_stack *heap)
{
	int	i;
	int	tmp;

	tmp = heap->sb[0];
	i = 0;
	while (i < heap->bcount - 1)
	{
		heap->sb[i] = heap->sb[i + 1];
		i++;
	}
	heap->sb[i] = tmp;
	write(1, "rb\n", 3);
}

int	*towards_the_end(int *arr, int size)
{
	int	i;

	i = size;
	while (i > 0)
	{
		arr[i] = arr[i - 1];
		i--;
	}
	return (arr);
}

int	*towards_the_start(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		arr[i] = arr[i + 1];
		i++;
	}
	return (arr);
}

void	buble_sort(t_stack *heap)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < heap->size -1)
	{
		if (heap->ssort[i] > heap->ssort[i + 1])
		{
			tmp = heap->ssort[i];
			heap->ssort[i] = heap->ssort[i + 1];
			heap->ssort[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}
