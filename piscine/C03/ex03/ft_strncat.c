/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geghevon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 09:23:41 by geghevon          #+#    #+#             */
/*   Updated: 2022/02/19 01:56:21 by geghevon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	ds;

	i = 0;
	ds = 0;
	while (dest[ds] != '\0')
		ds++;
	while (src[i] != '\0' && i < nb)
	{
		dest[ds] = src[i];
		ds++;
		i++;
	}
	dest[ds] = '\0';
	return (dest);
}
