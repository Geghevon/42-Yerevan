/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geghevon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:18:44 by geghevon          #+#    #+#             */
/*   Updated: 2022/07/05 21:18:50 by geghevon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_ptrlen(uintptr_t ptr)
{
	int	len;

	len = 0;
	while (ptr > 0)
	{
		len++;
		ptr = ptr / 16;
	}
	return (len);
}

void	ft_putptr(uintptr_t ptr)
{
	if (ptr >= 16)
	{
		ft_putptr(ptr / 16);
		ft_putptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar_fd((ptr + '0'), 1);
		else
			ft_putchar_fd((ptr - 10 + 'a'), 1);
	}
}

int	ft_ptr(unsigned long long p)
{
	int	len;

	len = 2;
	write(1, "0x", 2);
	if (p == 0)
	{
		len++;
		write(1, "0", 1);
	}
	else
	{
		ft_putptr(p);
		len = len + ft_ptrlen(p);
	}
	return (len);
}
