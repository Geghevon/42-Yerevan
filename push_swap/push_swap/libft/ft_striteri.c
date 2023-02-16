/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geghevon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 20:27:37 by geghevon          #+#    #+#             */
/*   Updated: 2022/03/26 20:27:42 by geghevon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t			len;
	unsigned int	i;

	i = 0;
	len = ft_strlen(s);
	if (s && f)
	{
		while (i < len)
		{
			f(i, s);
			i++;
			s++;
		}
	}
}
