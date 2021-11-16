/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 10:09:00 by avan-bre          #+#    #+#             */
/*   Updated: 2021/10/13 15:35:17 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	take_step(t_map *map, char *player, char *next)
{
	if (next[0] == '1')
		return (0);
	if (next[0] == 'E' && map->collected == map->collectibles)
		return (-1);
	if (next[0] == 'C')
		map->collected++;
	if (next[0] == 'E')
	{
		map->false_exit++;
		next[0] = 'P';
		player[0] = '0';
		return (1);
	}
	next[0] = 'P';
	if (map->false_exit)
	{
		player[0] = 'E';
		map->false_exit--;
	}
	else
		player[0] = '0';
	return (1);
}

int	move_left(t_double *all, int x, int y)
{
	char	*player;
	char	*next;
	int		outcome;

	player = &all->map->map[y][x];
	next = &all->map->map[y][x - 1];
	outcome = take_step(all->map, player, next);
	if (outcome == -1)
	{
		all->map->steps++;
		ft_putstr_fd("Final nr of steps: ", 1);
		ft_putnbr_fd(all->map->steps, 1);
		ft_putchar_fd('\n', 1);
		free_game(all);
		exit(0);
	}
	if (outcome)
	{
		all->map->player_x--;
		return (1);
	}
	return (0);
}

int	move_right(t_double *all, int x, int y)
{
	char	*player;
	char	*next;
	int		outcome;

	player = &all->map->map[y][x];
	next = &all->map->map[y][x + 1];
	outcome = take_step(all->map, player, next);
	if (outcome == -1)
	{
		all->map->steps++;
		ft_putstr_fd("Final nr of steps: ", 1);
		ft_putnbr_fd(all->map->steps, 1);
		ft_putchar_fd('\n', 1);
		free_game(all);
		exit(0);
	}
	if (outcome)
	{	
		all->map->player_x++;
		return (1);
	}
	return (0);
}

int	move_up(t_double *all, int x, int y)
{
	char	*player;
	char	*next;
	int		outcome;

	player = &all->map->map[y][x];
	next = &all->map->map[y - 1][x];
	outcome = take_step(all->map, player, next);
	if (outcome == -1)
	{
		all->map->steps++;
		ft_putstr_fd("Final nr of steps: ", 1);
		ft_putnbr_fd(all->map->steps, 1);
		ft_putchar_fd('\n', 1);
		free_game(all);
		exit(0);
	}
	if (outcome)
	{	
		all->map->player_y--;
		return (1);
	}
	return (0);
}

int	move_down(t_double *all, int x, int y)
{
	char	*player;
	char	*next;
	int		outcome;

	player = &all->map->map[y][x];
	next = &all->map->map[y + 1][x];
	outcome = take_step(all->map, player, next);
	if (outcome == -1)
	{
		all->map->steps++;
		ft_putstr_fd("Final nr of steps: ", 1);
		ft_putnbr_fd(all->map->steps, 1);
		ft_putchar_fd('\n', 1);
		free_game(all);
		exit(0);
	}
	if (outcome)
	{
		all->map->player_y++;
		return (1);
	}
	return (0);
}
