/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geghevon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 22:58:54 by geghevon          #+#    #+#             */
/*   Updated: 2022/12/01 22:58:57 by geghevon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error(char *str)
{
	ft_putstr_fd(str, 1);
	exit (EXIT_FAILURE);
	return (0);
}
