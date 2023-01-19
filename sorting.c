/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguyildi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:59:32 by uguyildi          #+#    #+#             */
/*   Updated: 2023/01/17 15:59:34 by uguyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_swap(t_stack *heap)
{
	if (heap->sa[0] > heap->sa[1])
		sa(heap);
}

void	three_swap(t_stack *heap)
{
	int	flag;

	flag = heap->sa[0];
	if (flag > heap->sa[1] && flag < heap->sa[2])
		sa(heap);
	else if ((flag < heap->sa[1] && flag > heap->sa[2]) && flag > heap->sa[2])
		rra(heap);
	else if (flag > heap->sa[1] && (heap->sa[1] > heap->sa[2]))
	{
		sa(heap);
		rra(heap);
	}
	else if (flag > heap->sa[1] && (heap->sa[1] < heap->sa[2]))
		ra(heap);
	else if (flag < heap->sa[1] && (heap->sa[1] > heap->sa[2]))
	{
		rra(heap);
		sa(heap);
	}
}

void	four_swap(t_stack *heap)
{
	int	small;

	small = smallest(heap);
	if (small == 1)
		sa(heap);
	if (small > 1)
	{
		while (small++ <= heap->size -1)
			rra(heap);
	}
	pb(heap);
	if (heap->size == 3)
	{
		three_swap(heap);
		while (heap->bcount > 0)
			pa(heap);
	}
	if (heap->size == 4 && heap->bcount > 0)
		four_swap(heap);
}
