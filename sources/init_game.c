/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:39:45 by avan-bre          #+#    #+#             */
/*   Updated: 2021/10/12 17:01:36 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	generate_tiles(t_game *data)
{
	int		width;
	int		height;

	data->cat = mlx_xpm_file_to_image(data->mlx, CAT, &width, &height);
	if (data->cat == NULL)
		return (0);
	data->fish = mlx_xpm_file_to_image(data->mlx, FISH, &width, &height);
	if (data->fish == NULL)
		return (0);
	data->floor = mlx_xpm_file_to_image(data->mlx, FLOOR, &width, &height);
	if (data->floor == NULL)
		return (0);
	data->wall = mlx_xpm_file_to_image(data->mlx, WALL, &width, &height);
	if (data->wall == NULL)
		return (0);
	data->exit = mlx_xpm_file_to_image(data->mlx, EXIT, &width, &height);
	if (data->exit == NULL)
		return (0);
	return (1);
}

int	start_game(t_map *map)
{
	t_game	data;

	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (0);
	data.win = mlx_new_window(data.mlx, map->width * 50, map->length * 50, SL);
	if (data.win == NULL)
		return (0);
	if (generate_tiles(&data) == 0)
		return (0);
	move_player((t_double){map, data});
	return (1);
}
