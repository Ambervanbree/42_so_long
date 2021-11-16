/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:05:59 by avan-bre          #+#    #+#             */
/*   Updated: 2021/10/25 12:24:58 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_lines(char *file)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	i = 0;
	line = get_next_line(fd);
	while (line != 0)
	{
		free_line(line);
		line = get_next_line(fd);
		i++;
	}
	free_line(line);
	close(fd);
	return (i);
}

void	fill_table(t_map *map, int fd)
{
	size_t	index;

	index = 0;
	while (index < map->length)
	{
		(map->map)[index] = get_next_line(fd);
		if ((map->map)[index][ft_strlen((map->map)[index]) - 1] == '\n')
			(map->map)[index][ft_strlen((map->map)[index]) - 1] = '\0';
		index++;
	}
	(map->map)[index] = 0;
}

int	initialise_map(char *file, t_map *map)
{	
	int		fd;

	map->length = count_lines(file);
	if (map->length == 0)
		return (return_function(0, -7));
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (return_function(0, -1));
	map->map = malloc((map->length + 1) * sizeof(char *));
	if (map->map == NULL)
		return (0);
	fill_table(map, fd);
	if (!(check_map(map) == 1))
		return (0);
	close(fd);
	return (1);
}

void	init_structure(t_map *map)
{
	map->map = 0;
	map->collected = 0;
	map->collectibles = 0;
	map->steps = 0;
	map->player = 0;
	map->exit = 0;
	map->false_exit = 0;
}

int	main(int argc, char *argv[])
{
	t_map	map;

	init_structure(&map);
	if (argc != 2)
	{
		return_function(0, -8);
		return (1);
	}
	if (check_filename(argv[1]) == 0)
	{
		return_function(0, -2);
		return (1);
	}
	if (initialise_map(argv[1], &map) == 0)
		return (1);
	if (start_game(&map) == 0)
	{
		return_function(map.map, -9);
		return (1);
	}
}
