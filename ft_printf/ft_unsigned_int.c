/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geghevon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:28:59 by geghevon          #+#    #+#             */
/*   Updated: 2022/07/05 21:29:03 by geghevon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_numlen(unsigned int c)
{
	int	len;

	len = 0;
	while (c > 0)
	{
		c = c / 10;
		len++;
	}
	return (len);
}

char	*ft_unsigned_itoa(unsigned int c)
{
	char	*num;
	int		len;

	len = ft_numlen(c);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!c)
		return (0);
	num[len] = '\0';
	while (c > 0)
	{
		num[--len] = c % 10 + 48;
		c = c / 10;
	}
	return (num);
}

int	ft_unsigned_int(unsigned int c)
{
	int		len;
	char	*num;

	len = 0;
	if (c == 0)
	{
		write(1, "0", 1);
		len = 1;
	}
	else
	{
		num = ft_unsigned_itoa(c);
		len = ft_printstr(num);
		free(num);
	}
	return (len);
}
