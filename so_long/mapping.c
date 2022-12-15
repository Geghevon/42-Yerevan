/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geghevon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 23:10:30 by geghevon          #+#    #+#             */
/*   Updated: 2022/12/01 23:10:32 by geghevon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	drawing(t_var t, char c, int yi, int xi)
{
	if (c == '1')
		t.gg.gg_ptr = mlx_xpm_file_to_image(t.maz, "./pics/wall.xpm",
				&t.gg.size.x, &t.gg.size.y);
	else if (c == '0')
		t.gg.gg_ptr = mlx_xpm_file_to_image(t.maz, "./pics/grass.xpm",
				&t.gg.size.x, &t.gg.size.y);
	else if (c == 'E')
		t.gg.gg_ptr = mlx_xpm_file_to_image(t.maz, "./pics/exit.xpm",
				&t.gg.size.x, &t.gg.size.y);
	else if (c == 'C')
		t.gg.gg_ptr = mlx_xpm_file_to_image(t.maz, "./pics/item.xpm",
				&t.gg.size.x, &t.gg.size.y);
	else if (c == 'P')
		t.gg.gg_ptr = mlx_xpm_file_to_image(t.maz, "./pics/gg_1.xpm",
				&t.gg.size.x, &t.gg.size.y);
	mlx_put_image_to_window(t.maz, t.win, t.gg.gg_ptr,
		SPRITE_W * xi, SPRITE_H * yi);
	mlx_destroy_image(t.maz, t.gg.gg_ptr);
	return (0);
}

int	sharing(t_var *t)
{
	int	xi;
	int	yi;

	yi = 0;
	while (yi < t->map.size.y - 1)
	{
		xi = 0;
		while (xi < t->map.size.x - 1)
		{
			drawing(*t, t->map.maz[yi][xi], yi, xi);
			xi++;
		}
		yi++;
	}
	return (0);
}

int	mapfree(t_var *t, char *str)
{
	int	yi;

	yi = 0;
	ft_putstr_fd(str, 1);
	mlx_destroy_window(t->maz, t->win);
	free(t->maz);
	while (yi < t->map.size.y)
	{
		free(t->map.maz[yi]);
		yi++;
	}
	free(t->map.maz);
	exit(0);
}

int	pressing(int key, t_var *t)
{
	int	stepped;

	stepped = t->game.step;
	if (key == ESC)
		mapfree(t, "GAME OVER\n");
	else
		moving(key, t, t->map.maz);
	if (stepped != t->game.step)
	{
		ft_putstr_fd("Stepped: ", 1);
		ft_putnbr_fd(t->game.step, 1);
		ft_putstr_fd("\n", 1);
	}
	sharing(t);
	return (0);
}

int	closing(t_var *t)
{
	mapfree(t, "The game is closed!\n");
	return (0);
}
