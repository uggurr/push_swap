/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguyildi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:56:46 by uguyildi          #+#    #+#             */
/*   Updated: 2023/01/17 15:56:50 by uguyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *heap)
{
	int	tmp;

	tmp = heap->sa[0];
	heap->sa[0] = heap->sa[1];
	heap->sa[1] = tmp;
	write(1, "sa\n", 3);
}

void	ra(t_stack *heap)
{
	int	i;
	int	tmp;

	tmp = heap->sa[0];
	i = 0;
	while (i < heap->size - 1)
	{
		heap->sa[i] = heap->sa[i + 1];
		i++;
	}
	heap->sa[i] = tmp;
	write(1, "ra\n", 3);
}

void	rra(t_stack *heap)
{
	int	len;
	int	tmp;

	len = heap->size - 1;
	tmp = heap->sa[len];
	while (len > 0)
	{
		heap->sa[len] = heap->sa[len - 1];
		len--;
	}
	heap->sa[len] = tmp;
	write(1, "rra\n", 4);
}

void	pb(t_stack *heap)
{
	towards_the_end(heap->sb, heap->bcount);
	heap->sb[0] = heap->sa[0];
	towards_the_start(heap->sa, heap->size);
	heap->bcount++;
	heap->size--;
	write(1, "pb\n", 3);
}
