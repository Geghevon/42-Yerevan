/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geghevon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:12:09 by geghevon          #+#    #+#             */
/*   Updated: 2022/02/23 19:15:29 by geghevon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, (str + i), 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	a;

	a = 1;
	while (a <= argc - 1)
	{
		ft_putstr(argv[a]);
		write(1, "\n", 1);
		a++;
	}
	return (0);
}
