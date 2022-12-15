/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geghevon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 22:24:17 by geghevon          #+#    #+#             */
/*   Updated: 2022/03/26 22:03:25 by geghevon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_len(int n)
{
	size_t	l;

	l = 0;
	if (n < 0)
		l++;
	else if (n == 0)
		l++;
	while (n != 0)
	{
		l++;
		n = n / 10;
	}
	return (l);
}

char	*ft_itoa(int n)
{
	long	num;
	int		len;
	char	*string;

	num = n;
	len = ft_len(num);
	string = malloc(sizeof(char) * (len + 1));
	if (num == 0)
		string[0] = '0';
	string[len] = '\0';
	if (num < 0)
	{
		string[0] = '-';
		num = -num;
	}
	while (len > 1)
	{
		string[len - 1] = (num % 10) + '0';
		num = num / 10;
		len--;
	}
	if (n > 0)
		string[0] = (num % 10) + '0';
	return (string);
}
