/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geghevon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:02:36 by geghevon          #+#    #+#             */
/*   Updated: 2022/02/19 09:08:58 by geghevon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
char	*ft_strcapitalize(char *str)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (j == 0 && str[i] <= 122 && str[i] >= 97)
			str[i] = str[i] - 32;
		if (j != 0 && str[i] >= 65 && str[i] <= 90)
			str[i] = str[i] + 32;
		j++;
		if (str[i] < 48 || str[i] > 57)
				if (str[i] < 65 || str[i] > 90)
					if (str[i] < 97 || str[i] > 122)
						i = 0;
		i++;
	}
	return (str);
}
