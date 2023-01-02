#include "push_swap.h"

void	ft_free_split(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
}

int	getcount(char **s)
{
	char	**a;
	int		i;
	int		j;
	int		count;

	i = 1;
	while (s[i])
	{
		j = -1;
		a = ft_split(*s, ' ');
		while (a[++j])
			count++;
		i++;
		ft_free_split(a);
	}
	return (count);
}

int	*getarg(char *s)
{
	char	**a;
	int		*b;
	int		i;

	i = 0;
	a = ft_split(s, ' ');
	b = malloc(getcount(a));
	while (a[i])
	{
		b[i] = ft_atoi(a[i]);
		i++;
	}
	ft_free_split(a);
	return (b);
}

int	main(int ag, char **av)
{
	int	i;
	int	*arr;
	int	j;
	int	*sp;
	int	x;

	x = -1;
	i = -1;
	arr = malloc(getcount(av));
	while (av[++i])
	{
		j = -1;
		sp = getarg(av[i]);
		while (sp[++j])
			arr[++x] = sp[j];
	}
	free(sp);
}
