/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geghevon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:27:31 by geghevon          #+#    #+#             */
/*   Updated: 2022/03/23 19:27:33 by geghevon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	k;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	k = dst_len;
	i = 0;
	if (dst_len < (dstsize - 1) && dstsize > 0)
	{
		while (src[i] && dst_len + i < dstsize - 1)
		{
			dst[k] = src[i];
			i++;
			k++;
		}
		dst[k] = 0;
	}
	else if (dst_len >= dstsize)
		dst_len = dstsize;
	return (dst_len + src_len);
}
