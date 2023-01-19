/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguyildi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:59:05 by uguyildi          #+#    #+#             */
/*   Updated: 2023/01/17 15:59:08 by uguyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*sa;
	int	*sb;
	int	maxbit;
	int	*ssort;
	int	size;
	int	bcount;
}		t_stack;

typedef struct s_arg
{
	char	**a;
	int		i;
	int		j;
	int		count;
}		t_arg;

int		get_count(char **ag);
void	all_free(t_stack *heap);
void	get_arg(t_stack *heap, char **av);
void	atoi_check(char **a);
int		smallest(t_stack *heap);
void	sorted_list(t_stack *heap);
void	buble_sort(t_stack *heap);
void	find_maxbit(t_stack *heap);
int		find_index(t_stack *heap, int nbr, int size);
void	radix(t_stack *heap);
int		*towards_the_end(int *arr, int size);
int		*towards_the_start(int *arr, int size);
void	two_swap(t_stack *heap);
void	three_swap(t_stack *heap);
void	four_swap(t_stack *heap);
void	sa(t_stack *heap);
void	ra(t_stack *heap);
void	rb(t_stack *heap);
void	pa(t_stack *heap);
void	pb(t_stack *heap);
void	rra(t_stack *heap);
#endif
