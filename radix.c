/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguyildi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:59:17 by uguyildi          #+#    #+#             */
/*   Updated: 2023/01/17 15:59:20 by uguyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_maxbit(t_stack *heap)
{
	int	max;

	heap->maxbit = 0;
	max = heap->size - 1;
	while (max > 0)
	{
		heap->maxbit++;
		max /= 2;
	}
}

int	find_index(t_stack *heap, int nbr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (heap->ssort[i] == nbr)
			return (i);
		i++;
	}
	return (0);
}

void	radix(t_stack *heap)
{
	int	i;
	int	j;
	int	alen;

	i = 0;
	alen = heap->size;
	while (i < heap->maxbit)
	{
		j = 0;
		while (j < alen)
		{
			if ((find_index(heap, heap->sa[0], alen) >> i & 1))
				ra(heap);
			else
				pb(heap);
			j++;
		}
		while (heap->bcount)
			pa(heap);
		i++;
	}
}
