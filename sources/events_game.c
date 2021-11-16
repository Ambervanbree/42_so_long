/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:24:53 by avan-bre          #+#    #+#             */
/*   Updated: 2021/10/13 13:58:27 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_images(t_map map, t_game data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map.length * 50)
	{
		j = 0;
		while (j < map.width * 50)
		{
			if (map.map[i / 50][j / 50] == '1')
				mlx_put_image_to_window(data.mlx, data.win, data.wall, j, i);
			if (map.map[i / 50][j / 50] == '0')
				mlx_put_image_to_window(data.mlx, data.win, data.floor, j, i);
			if (map.map[i / 50][j / 50] == 'C')
				mlx_put_image_to_window(data.mlx, data.win, data.fish, j, i);
			if (map.map[i / 50][j / 50] == 'P')
				mlx_put_image_to_window(data.mlx, data.win, data.cat, j, i);
			if (map.map[i / 50][j / 50] == 'E')
				mlx_put_image_to_window(data.mlx, data.win, data.exit, j, i);
			j += 50;
		}
		i += 50;
	}
}

int	render(t_double *all)
{
	if (all->data.win != NULL)
		load_images(*all->map, all->data);
	return (0);
}

int	keypress(int keysym, t_double *all)
{
	int	x;
	int	y;
	int	next;

	x = all->map->player_x;
	y = all->map->player_y;
	next = 0;
	if (keysym == KEY_ESC)
		free_game(all);
	if (keysym == KEY_A)
		next = move_left(all, x, y);
	if (keysym == KEY_D)
		next = move_right(all, x, y);
	if (keysym == KEY_W)
		next = move_up(all, x, y);
	if (keysym == KEY_S)
		next = move_down(all, x, y);
	if (next == 1)
	{
		all->map->steps++;
		ft_putstr_fd("Nr of steps: ", 1);
		ft_putnbr_fd(all->map->steps, 1);
		ft_putchar_fd('\n', 1);
	}
	return (1);
}

int	mouseclick(t_double *all)
{
	free_game(all);
	return (0);
}

void	move_player(t_double all)
{
	mlx_loop_hook(all.data.mlx, &render, &all);
	mlx_key_hook(all.data.win, &keypress, &all);
	mlx_hook(all.data.win, 17, 1L << 0, &mouseclick, &all);
	mlx_loop(all.data.mlx);
}
