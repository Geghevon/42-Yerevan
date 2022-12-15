/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goganisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:25:26 by goganisi          #+#    #+#             */
/*   Updated: 2022/02/24 00:34:14 by goganisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void check_user_input(int argc, char **argv, char numberp[]);
int check_input(char *str, char num[]);
void ft_atoi(char num[], char *str, int i, int j);
int ft_isspace(char c);
int check_0(char *str, int i);
void fill_0(char *str, char c);
int	ft_dot(char *str);


char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}


void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while(str[++i])
		ft_putchar(str[i]);
}


int	ft_strlen(char *str)
{
	int	i;
	i = 0;
	while(str[i])
		++i;
	return (i);
}


void	print_number(char *num, char lib[1000][1000])
{
	int	len;
	int	i;
	int iter = 0;
	int j;

	len = ft_strlen(num);
	i = -1;
		
	while (num[++i] && len)
	{	
		if (len % 3 == 0 && num[i] != '0')    		    // yete haryuravor e
		{
			ft_putstr(lib[num[i] - 48]);    	      // tpir 1ic 9ny
			ft_putchar(' ');
			ft_putstr(lib[28]);            	   		    // tpir haryur
			ft_putchar(' ');
		}
		else if (len % 3 == 2)              		     // yete tasnavor e
		{
			if (num[i] == '1')							 // yete tasnavory 10e`
			{
				ft_putstr(lib[num[i + 1] - 38]);  		// tpir 10ic 19y
				ft_putchar(' ');
			}
			else if (num[i] != '0')						 
			{
				ft_putstr(lib[num[i] - 30]); 	// tpum e 20ic 30n
				ft_putchar(' ');
			}
		}
		else 				// ayl depqum - miavor tpir -------
		{
			if(num[i] > '0') 
			{
				if (iter) // naxatesvac e i=0i depqum, vor stringic durs chga (i=-1mek)
				{
					if (num[i - 1] != '1')
						ft_putstr(lib[num[i] - 48]);  // tpir miavor (1ic 9ny)
				} 
				else			
					ft_putstr(lib[num[i] - 48]);  // tpir 1ic 9y
				ft_putchar(' ');
				j = 0;
				while (++j <= 12)  // es cikly voroshum a te vor hazaravori vra es kangnac (nonillion - hazar)
				{
					if (len == 3 * j + 1)
					{
						ft_putstr(lib[28 + j]);  // hazaravorneri tpox tox (28y gradaranum haryurn a)
						ft_putchar(' ');
					}
				}
			}
		}
		iter++;  // erkrord eryak
		len--;
	}
	ft_putchar('\n');
}

int	main(int argc, char **argv)
{
	int		fd;
	char	buf[1001];
	char	input_nb[255];
	char	numbers_array[1000][1000];
	int		i[3];

	fd = 0;
	i[0] = 0;;
	if (argc == 1)
	{
		read(0, &input_nb, 254);
		check_user_input(argc, argv, input_nb);
		
//	ft_putstr(input_nb);
	}
	else if (argc > 3)
		return (0);
	else if (argc == 2)
	{
		fd = open("numbers.dict", O_RDONLY);
		ft_strcpy(input_nb, argv[1]);
		check_user_input(argc, argv, input_nb);
	}
	else
	{	
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr("Error");
			return (0);
		}
		ft_strcpy(input_nb, argv[2]);
	}
	if (fd > 0)
		read(fd, &buf, 1000);
	close(fd);
	i[1] = 0;
	i[2] = 0;
	while (buf[i[0]])
	{
		if (buf[i[0]] == '\n')
		{
			i[1] = 0;
			i[2]++;
		}
		else if (((buf[i[0]] >= 'a' && buf[i[0]] <= 'z')
				|| (buf[i[0]] >= 'A' && buf[i[0]] <= 'Z')))
		{
			numbers_array[i[2]][i[1]] = buf[i[0]];
			i[1]++;
		}
		i[0]++;
	}
//	ft_putstr(input_nb);
	print_number(input_nb, numbers_array);
	return (0);
}
