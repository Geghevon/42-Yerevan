#include <stdio.h>
#include <unistd.h>
void check_user_input(int argc, char **argv);
int check_input(char *str, char num[]);
void ft_atoi(char num[], char *str, int i, int j);
int ft_isspace(char c);
int check_0(char *str, int i);
void fill_0(char *str, char c);
int	ft_dot(char *str);

int main (int argc, char **argv)
{
	check_user_input(argc, argv);
	return (0);
}

void check_user_input(int argc, char **argv)
{
	char number[255];

	fill_0(number, '#');
	if (argc == 2)
	{
		if (check_input(argv[1], number) == 1)
		{
			printf("%s", number);
		}
		else
			write(1, "Error", 5);
	}
	else if (argc == 3)
	{
		if (check_input(argv[2], number) == 1)
			write(1, &number, 1);
		else
			write(1, "Error", 5);
	}
	else
		write(1, "Error", 5);
}

int check_input(char *str, char num[])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	num[39] = '\0';
	num[0] = '\0';
	ft_atoi(num, str, i, j);
	if (num[0] == '\0' || num[39] != '\0')
		return (-1);
	else
		return(1);
}

void ft_atoi(char num[], char *str, int i, int j)
{
	if (str[0] == '\0')
		return ;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		return ;
	if (str[i] < '0' || str[i] > '9' || ft_dot(str))
		return ;
	if (str[i] == 46 && (str[i - 1] >= 48 || str[i - 1] <= 57))
		return ;
	if (check_0(str, i))
	{
		num[0] = '0';
		num[1] = '\0';
		return ;
	}
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num[j] = str[i];
		i++;
		j++;
	}
	num[j] = '\0';
}

int ft_isspace(char c)
{
	char *str;
	int i;

	str = " \f\n\r\t\v";
	i = 0;
	while (str[i] != '\0')
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int check_0(char *str, int i)
{
	while (str[i] == '0')
		i++;
	if (str[i] == '\0')
		return (1);
	else
		return (0);
}

void fill_0(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = c;
		i++;
	}
}

int	ft_dot(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if ((str[i] >=48 && str[i] <= 57) && ((str[i + 1] >= 0 && str[i + 1] <= 45) || str[i + 1] == 47 || str[i + 1] > 57))
			return (0);
		else if (str[i] == 46 && (str[i - 1] >= 48 && str[i - 1] <= 57))
			return(1);
		i++;
	}
	return (0);
}
