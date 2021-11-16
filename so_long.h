/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 09:59:07 by avan-bre          #+#    #+#             */
/*   Updated: 2021/10/25 11:48:50 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifdef __linux__
#  define KEY_W		119
#  define KEY_A		97
#  define KEY_S		115
#  define KEY_D		100
#  define KEY_ESC	   65307
# else
#  define KEY_W		13
#  define KEY_S		1
#  define KEY_A		0
#  define KEY_D		2
#  define KEY_ESC	53
# endif

# define FLOOR "./Images/floor.xpm"
# define WALL "./Images/wall.xpm"
# define CAT "./Images/cat.xpm"
# define FISH "./Images/fish.xpm"
# define EXIT "./Images/exit.xpm"
# define BLOCK "./Images/block.xpm"
# define SL "./so_long"

# include "libft/libft.h"
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_map {
	char	**map;
	size_t	length;
	size_t	width;
	size_t	player_x;
	size_t	player_y;
	size_t	collectibles;
	size_t	player;
	size_t	exit;
	size_t	collected;
	size_t	steps;
	size_t	false_exit;
}				t_map;

typedef struct s_game {
	void	*mlx;
	void	*win;
	void	*img;
	void	*cat;
	void	*fish;
	void	*wall;
	void	*floor;
	void	*exit;
	void	*block;
}				t_game;

typedef struct s_double {
	t_map	*map;
	t_game	data;
}				t_double;

int		check_map(t_map *map);
int		return_function(char **map, int code);
int		check_filename(char *file);
void	print_map(char **map);
int		start_game(t_map *map);
void	move_player(t_double all);
int		keypress(int keysym, t_double *all);
void	free_game(t_double *all);
int		move_left(t_double *all, int x, int y);
int		move_right(t_double *all, int x, int y);
int		move_up(t_double *all, int x, int y);
int		move_down(t_double *all, int x, int y);
char	*string_steps(t_double all);
void	free_line(char *line);
void	write_steps(t_double *all);

#endif