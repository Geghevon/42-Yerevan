/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geghevon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 23:05:23 by geghevon          #+#    #+#             */
/*   Updated: 2022/12/01 23:05:26 by geghevon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	xy(t_var *t, char *map_name)
{
	int		fd;
	char	*dash;

	t->map.size.x = 0;
	t->map.size.y = 0;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		error("There is no map!");
	dash = get_next_line(fd);
	t->map.size.x = ft_strlen(dash);
	while (dash)
	{
		t->map.size.y++;
		free(dash);
		dash = get_next_line(fd);
	}
	t->map.size.y++;
	free(dash);
	close(fd);
	return (0);
}

int	mapping(t_var *t, char *map_name)
{
	int	yi;
	int	fd;

	t->map.maz = malloc(sizeof(char *) * (t->map.size.y + 1));
	t->map.maz[t->map.size.y - 1] = NULL;
	t->game.step = 0;
	yi = 0;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		error("There is no map!");
	t->map.maz[yi] = get_next_line(fd);
	while (t->map.maz[yi])
	{
		yi++;
		t->map.maz[yi] = get_next_line(fd);
	}
	close(fd);
	return (0);
}

int	check_arg(int argc, char **argv)
{
	if (argc != 2)
		error("The number of the arguments isn't correct!");
	if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
		error("Map extension isn't correct!");
	return (0);
}

int	main(int argc, char **argv)
{
	t_var	t;

	check_arg(argc, argv);
	xy(&t, argv[1]);
	mapping(&t, argv[1]);
	check_walls(t);
	check_epc(t);
	charandlencheck(t.map.maz, t);
	t.maz = mlx_init();
	t.win = mlx_new_window(t.maz, (t.map.size.x - 1) * SPRITE_W,
			(t.map.size.y - 1) * SPRITE_H, "GAME");
	position(&t);
	sharing(&t);
	mlx_hook(t.win, X_EVENT_KEY_PRESS, 1L << 0, pressing, &t);
	mlx_hook(t.win, X_EVENT_KEY_EXIT, 1L << 0, closing, &t);
	mlx_expose_hook(t.win, sharing, &t);
	mlx_loop(t.maz);
	return (0);
}
