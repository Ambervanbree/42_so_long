/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:10:32 by avan-bre          #+#    #+#             */
/*   Updated: 2021/10/25 11:01:40 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_line(char *line)
{
	if (line)
	{
		free(line);
		line = NULL;
	}
}

void	print_map(char **map)
{
	int	index;

	index = 0;
	while (map[index] != 0)
	{
		printf("%s\n", map[index]);
		index++;
	}
}

void	free_game(t_double *all)
{
	mlx_destroy_image(all->data.mlx, all->data.cat);
	all->data.cat = NULL;
	mlx_destroy_image(all->data.mlx, all->data.fish);
	all->data.fish = NULL;
	mlx_destroy_image(all->data.mlx, all->data.floor);
	all->data.floor = NULL;
	mlx_destroy_image(all->data.mlx, all->data.wall);
	all->data.wall = NULL;
	mlx_destroy_image(all->data.mlx, all->data.exit);
	all->data.exit = NULL;
	mlx_destroy_window(all->data.mlx, all->data.win);
	all->data.win = NULL;
	return_function(all->map->map, 1);
	free(all->data.mlx);
	all->data.mlx = NULL;
	exit(0);
}

static void	print_error_message(int code)
{
	if (code == -1)
		ft_putstr_fd("File could not be opened\n", 1);
	if (code == -2)
		ft_putstr_fd("File is not valid\n", 1);
	if (code == -3)
		ft_putstr_fd("Map is not surrounded by walls\n", 1);
	if (code == -4)
		ft_putstr_fd("Map contains (an) invalid character(s)\n", 1);
	if (code == -5)
		ft_putstr_fd("Map does not contain all necessary characters", 1);
	if (code == -6)
		ft_putstr_fd("Map is not rectangular, doofus\n", 1);
	if (code == -7)
		ft_putstr_fd("Map is empty\n", 1);
	if (code == -8)
		ft_putstr_fd("Function must have exactly one argument\n", 1);
	if (code == -9)
		ft_putstr_fd("Program failed to start the game\n", 1);
}

int	return_function(char **map, int code)
{
	int	index;

	index = 0;
	if (map)
	{	
		while (map[index] != 0)
		{
			free(map[index]);
			map[index] = NULL;
			index++;
		}
		free(map);
		map = 0;
	}
	if (code == 1)
		return (1);
	ft_putstr_fd("Error\n", 1);
	print_error_message(code);
	return (0);
}
