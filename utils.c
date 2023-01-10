#include "push_swap.h"

int	is_it_number(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && ft_isdigit(str[i + 1]))
		i++;
	else if (!ft_isdigit(str[i]))
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	get_count(char **ag)
{
	t_arg	p;

	p.count = 0;
	p.i = 0;
	while (ag[++p.i])
	{
		p.j = -1;
		p.a = ft_split(ag[p.i], ' ');
		while (p.a[++p.j])
		{
			if (!is_it_number(p.a[p.j]))
			{
				write (2, "Error\n", 6);
				return (0);
			}
			p.count++;
			free(p.a[p.j]);
		}
		if (ag[0] == NULL)
			return (0);
		free(p.a);
	}
	return (p.count);
}

void	get_arg(t_stack *heap, char **av)
{
	char	**a;
	int		i;
	int		j;
	int		x;

	x = 0;
	i = 0;
	while (av[++i])
	{
		a = ft_split(av[i], ' ');
		j = 0;
		while (a[j])
		{
			heap->sa[x] = ft_atoi(a[j]);
			free(a[j]);
			x++;
			j++;
		}
		free(a);
	}
}
