/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geghevon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 23:07:45 by geghevon          #+#    #+#             */
/*   Updated: 2022/12/11 15:20:53 by geghevon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls(t_var t)
{
	int	xi;
	int	yi;

	yi = 0;
	while (yi < t.map.size.y - 1)
	{
		xi = 0;
		if (t.map.maz[yi][0] != '1' || t.map.maz[yi][t.map.size.x - 2] != '1')
			error("Side walls aren't ok!");
		if (yi == 0 || yi == t.map.size.y - 2)
		{
			while (xi < t.map.size.x - 1)
			{
				if (t.map.maz[yi][xi] != '1')
					error("Top or down wall isn't ok!");
				xi++;
			}
		}
		yi++;
	}
	return (0);
}

int	check_epc(t_var t)
{
	int	xi;
	int	yi;
	int	epc[3];

	yi = 0;
	epc[0] = 0;
	epc[1] = 0;
	epc[2] = 0;
	while (++yi < t.map.size.y - 1)
	{
		xi = 0;
		while (++xi < t.map.size.x - 1)
		{
			if (t.map.maz[yi][xi] == 'P')
				epc[0]++;
			else if (t.map.maz[yi][xi] == 'C')
				epc[1]++;
			else if (t.map.maz[yi][xi] == 'E')
				epc[2]++;
		}
	}
	if (epc[0] != 1 || epc[1] < 1 || epc[2] != 1)
		error ("The number of E, P or C isn't correct!");
	t.game.coll = epc[1];
	return (0);
}

int	charandlencheck(char **arr, t_var t)
{
	int	xi;
	int	yi;

	yi = 0;
	while (yi < t.map.size.y - 1)
	{
		xi = -1;
//		if (yi != t.map.size.y - 2)
//		{
			if ((int)ft_strlen(arr[yi]) != t.map.size.x)
				error("The map isn't a rectangle!");
//		}
//		else
//			if ((int)ft_strlen(arr[yi]) != t.map.size.x - 1)
//				error("The map isn't a rectangle!");
		while (++xi < t.map.size.x - 2)
			if (arr[yi][xi] != '1' && arr[yi][xi] != '0' && arr[yi][xi] != 'P'
					&& arr[yi][xi] != 'E' && arr[yi][xi] != 'C')
				error("Error in the map characters!");
		yi++;
	}
	return (0);
}

int	position(t_var *t)
{
	int	xi;
	int	yi;

	yi = 1;
	while (yi < t->map.size.y - 1)
	{
		xi = 1;
		while (xi < t->map.size.x - 1)
		{
			if (t->map.maz[yi][xi] == 'P')
			{
				t->gg.pos.x = xi;
				t->gg.pos.y = yi;
			}
			xi++;
		}
		yi++;
	}
	return (0);
}

int	collcheck(t_var *t)
{
	int	xi;
	int	yi;
	int	i;

	yi = 0;
	i = 0;
	while (++yi < t->map.size.y - 1)
	{
		xi = 0;
		while (++xi < t->map.size.x - 1)
			if (t->map.maz[yi][xi] == 'C')
				i++;
	}
	if (i == 0)
		mapfree(t, "YOU WON!\n");
	else
		ft_putstr_fd("Collect them all!\n", 1);
	return (0);
}
