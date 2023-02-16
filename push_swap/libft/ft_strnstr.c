/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geghevon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:33:45 by geghevon          #+#    #+#             */
/*   Updated: 2022/03/23 19:35:45 by geghevon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;
	char	*hay;

	i = 0;
	hay = (char *)haystack;
	if (needle[0] == '\0')
		return (hay);
	while (hay[i])
	{
		k = 0;
		while (hay[i + k] == needle[k] && (i + k) < len)
		{
			if (hay[i + k] == '\0' && needle[k] == '\0')
				return (&hay[i]);
			k++;
		}
		if (needle[k] == '\0')
			return (&hay[i]);
		i++;
	}
	return (0);
}
