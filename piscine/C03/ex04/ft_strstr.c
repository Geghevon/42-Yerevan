/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geghevon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 20:39:11 by geghevon          #+#    #+#             */
/*   Updated: 2022/02/19 09:39:04 by geghevon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (*s1 && *s2 && i < n)
	{
		if (*s1 > *s2)
			return (1);
		else if (*s1 < *s2)
			return (-1);
		s1++;
		s2++;
		i++;
	}
	if (i < n)
	{
		if (*s1)
			return (1);
		else if (*s2)
			return (-1);
	}
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int				i;
	unsigned int	tf;

	i = 0;
	tf = ft_strlen(to_find);
	if (tf < 1)
		return (str);
	while (str[i] != '\0')
	{
		if (str[i] == *to_find)
		{
			if (ft_strncmp(str + i, to_find, tf) == 0)
				return (str + i);
			tf++;
		}
		i++;
	}
	return (0);
}
