#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack
{
	int	*sa;
	int	*sb;
	int	size;
}		t_stack;

typedef struct s_arg
{
	char	**a;
	int		i;
	int		j;
	int		count;
}		t_arg;

int		get_count(char **ag);
void	get_arg(t_stack *heap, char **av);
void	two_swap(t_stack *heap);
void	sa(t_stack *heap);
