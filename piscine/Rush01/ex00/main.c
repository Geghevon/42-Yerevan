#include <stdlib.h>
#include <unistd.h>


void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}


int check_num(int i, int j, char board[4][5])
{
	int d;
	
	d = 0;
	while (d++ < 4)
	{
		if (j != d)
			if (board[i][j] == board[i][d])
				return (0);
		if (i != d)
			if (board[i][j] == board[d][j])
				return (0);
	}
	return (1);
}




int backtracking(char board[4][5])
{
	int i;
	int j;

	i = 0;

	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			board[i][j] = 0;
			j++;
		}
	i++;
	}
	i = 0;
	j = 0;

	while (i < 4)
	{
		while (j < 4)
		{
			board[i][j]++;
			if (checknum(board[i][j]))
			{
				j++;			
			}
			else if (j == 3)
				i--;
		}
		i++;
		j = 0;
	}
}



int	main(int argc, char **argv)
{
	char	rules[4][5];
	char	board[4][5];
	int		i;
	int 	j;
	int 	counter;

	if (argc != 2)
		return (0);
	i = 0;
	counter = 0;
	while (i < 4)
	{
		j = 0;
		while (j <= 4)
		{
			rules[i][j] = argv[1][counter];
			if (j == 4)
				rules[i][j] = '\0';
			else
				counter += 2;
			j++;
		}
		i++;
	}
	return (0);
}
