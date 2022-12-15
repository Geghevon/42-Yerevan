#include "push_swap.h"

int number_check(int ac, char **av)
{
	int i;
	int j;

	i = 1;
	while(i < ac)
	{
		j = 0;
		if(av[i][0] == '-' && av[i][1] != '\0')
			j++;
		while(av[i][j])
		{
			if(av[i][j] >= 48 && av[i][j] <= 57)
				j++;
			else
				error("Check the arguments!");
		}
		i++;
	}
	return(0);
}

int max_min_check(int ac, char **av)
{
	long	num;
	int		i;
	int		j;
	int		neg;

	i = 0;
	neg = 1;
	while(i < ac)
	{
		j = 0;
		num = 0;
		if(av[i][0] == '-')
		{
			neg *= -1;
			j++;
		}
		while(av[i][j++])
			num = num * 10 + (av[i][j] - '0');
		if(fast_check(num, neg))
			error("Check the arguments!");
		i++;
	}
	return(0);
}

int	fast_check(long	num, int neg)
{
	if(neg == -1)
		num *= -1;
	if(num > INT_MAX || num < INT_MIN)
		return(1);
	return(0);
}

int	fill_numbers(int ac, char **av, t_helping *t)
{
	int	i;

	i = 0;
	while(i < ac - 1)
	{
		t->numbers[i] = ft_atoi(av[i + 1]);
		i++;
	}
	return(0);
}

int	dup_check(int ac, char **argv, t_helping *t)
{
	int	i;
	int	j;

	i = 0;
	while(i < ac - 1)
	{
		j = i + 1;
		while(j < ac - 1)
		{
			if(t->numbers[i] == t->numbers[j])
			{
				free(t->numbers);
				error("There are duplicates!");
			}
			j++;
		}
		i++;
	}
	return(0);
}