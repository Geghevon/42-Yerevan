/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geghevon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 23:12:34 by geghevon          #+#    #+#             */
/*   Updated: 2022/12/01 23:12:36 by geghevon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# include "mlx/mlx.h"
# include "libft/libft.h"

# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_EXIT	17

# define A_KEY		0
# define S_KEY		1
# define D_KEY		2
# define W_KEY		13
# define ESC		53

# define SPRITE_H	32
# define SPRITE_W	32

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_gg
{
	void		*gg_ptr;
	t_vector	size;
	t_vector	pos;
	int			*addr;
	int			bpp;
	int			line_len;
	int			endian;
}	t_gg;

typedef struct s_map
{
	char		**maz;
	t_vector	size;
}	t_map;

typedef struct s_game
{
	int		coll;
	int		step;
}	t_game;

typedef struct s_var
{
	void	*maz;
	void	*win;
	t_game	game;
	t_map	map;
	t_gg	gg;
}	t_var;

int	main(int argc, char **argv);
int	check_arg(int argc, char **argv);
int	mapping(t_var *t, char *map_name);
int	xy(t_var *t, char *map_name);
int	check_walls(t_var t);
int	check_epc(t_var t);
int	position(t_var *t);
int	collcheck(t_var *t);
int	error(char *str);
int	charandlencheck(char **arr, t_var t);
int	drawing(t_var t, char c, int yi, int xi);
int	sharing(t_var *t);
int	mapfree(t_var *t, char *str);
int	pressing(int key, t_var *t);
int	moving(int key, t_var *t, char **maz);
int	left(t_var *t);
int	right(t_var *t);
int	down(t_var *t);
int	up(t_var *t);
int	closing(t_var *t);

#endif
