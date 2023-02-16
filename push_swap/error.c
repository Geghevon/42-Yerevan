/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geghevon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 22:58:54 by geghevon          #+#    #+#             */
/*   Updated: 2022/12/18 14:41:38 by geghevon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(char *str, t_stack **a, t_stack **b, t_helping *t)
{
	if (a && b && t)
		frees(a, b, t);
	else if (!a && !b && t)
		frees(NULL, NULL, t);
	else if (a && !b && t)
		frees(a, NULL, t);
	ft_putstr_fd(str, 2);
	exit (1);
	return (0);
}
