/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:14:19 by avan-bre          #+#    #+#             */
/*   Updated: 2021/10/12 14:29:34 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_filename(char *file)
{
	int		index;

	index = ft_strlen(file) - 1;
	if (file[index] == 'r')
		if (file[index - 1] == 'e')
			if (file[index - 2] == 'b')
				if (file[index - 3] == '.')
					if ((index - 3) > 0)
						if (file[index - 4] != '/')
							return (1);
	return (0);
}

static int	border_check(char *line)
{
	int		index;

	index = 0;
	while (line[index] != '\0')
	{
		if (line[index] != '1')
			return (0);
		index++;
	}
	return (1);
}

static int	char_check(char *line)
{
	int		index;

	index = 0;
	while (line[index] != '\0')
	{
		if (!(in_set(line[index], "10CPE")))
			return (0);
		index++;
	}
	return (1);
}

static	int	line_check(t_map *map, int line)
{
	int			index;

	index = 0;
	while (map->map[line][index] != '\0')
	{
		if (map->map[line][index] == 'C')
			map->collectibles++;
		if (map->map[line][index] == 'P')
		{
			map->player++;
			map->player_x = index;
			map->player_y = line;
		}
		if (map->map[line][index] == 'E')
			map->exit++;
		index++;
	}
	if (map->map[line][0] != '1' || map->map[line][index - 1] != '1')
		return (0);
	return (1);
}

int	check_map(t_map *map)
{
	size_t		index;

	map->width = ft_strlen(map->map[0]);
	if (border_check(map->map[map->length - 1]) == 0
		|| border_check(map->map[0]) == 0)
		return (return_function(map->map, -3));
	if (ft_strlen(map->map[map->length - 1]) != map->width)
		return (return_function(map->map, -6));
	index = 0;
	while (index < map->length)
	{
		if (!(line_check(map, index)))
			return (return_function(map->map, -3));
		if (ft_strlen(map->map[index]) != map->width)
			return (return_function(map->map, -6));
		if (!(char_check(map->map[index])))
			return (return_function(map->map, -4));
		index++;
	}
	if (map->collectibles < 1 || map->player < 1 || map->exit < 1)
		return (return_function(map->map, -5));
	if (map->player > 1)
		return (return_function(map->map, -4));
	return (1);
}
