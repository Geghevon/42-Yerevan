/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geghevon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 23:11:52 by geghevon          #+#    #+#             */
/*   Updated: 2022/12/01 23:12:08 by geghevon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	up(t_var *t)
{
	t->map.maz[t->gg.pos.y][t->gg.pos.x] = '0';
	t->gg.pos.y++;
	t->map.maz[t->gg.pos.y][t->gg.pos.x] = 'P';
	t->game.step++;
	return (0);
}

int	down(t_var *t)
{
	t->map.maz[t->gg.pos.y][t->gg.pos.x] = '0';
	t->gg.pos.y--;
	t->map.maz[t->gg.pos.y][t->gg.pos.x] = 'P';
	t->game.step++;
	return (0);
}

int	right(t_var *t)
{
	t->map.maz[t->gg.pos.y][t->gg.pos.x] = '0';
	t->gg.pos.x++;
	t->map.maz[t->gg.pos.y][t->gg.pos.x] = 'P';
	t->game.step++;
	return (0);
}

int	left(t_var *t)
{
	t->map.maz[t->gg.pos.y][t->gg.pos.x] = '0';
	t->gg.pos.x--;
	t->map.maz[t->gg.pos.y][t->gg.pos.x] = 'P';
	t->game.step++;
	return (0);
}

int	moving(int key, t_var *t, char **maz)
{
	if (key == A_KEY && maz[t->gg.pos.y][t->gg.pos.x - 1] == 'E')
		collcheck(t);
	else if (key == A_KEY && maz[t->gg.pos.y][t->gg.pos.x - 1] != '1')
		left(t);
	if (key == D_KEY && maz[t->gg.pos.y][t->gg.pos.x + 1] == 'E')
		collcheck(t);
	else if (key == D_KEY && maz[t->gg.pos.y][t->gg.pos.x + 1] != '1')
		right(t);
	if (key == S_KEY && maz[t->gg.pos.y + 1][t->gg.pos.x] == 'E')
		collcheck(t);
	else if (key == S_KEY && maz[t->gg.pos.y + 1][t->gg.pos.x] != '1')
		up(t);
	if (key == W_KEY && maz[t->gg.pos.y - 1][t->gg.pos.x] == 'E')
		collcheck(t);
	else if (key == W_KEY && maz[t->gg.pos.y - 1][t->gg.pos.x] != '1')
		down(t);
	return (0);
}
