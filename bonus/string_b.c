/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:39:08 by avan-bre          #+#    #+#             */
/*   Updated: 2021/10/25 12:31:36 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*string_steps(t_double all)
{
	char	*number;
	char	*string;

	number = ft_itoa(all.map->steps);
	string = ft_strjoin("Nr of steps: ", number);
	free (number);
	number = NULL;
	return (string);
}

void	write_steps(t_double *all)
{
	char	*string;

	string = string_steps(*all);
	mlx_put_image_to_window(all->data.mlx, all->data.win,
		all->data.block, 0, all->map->length * 50);
	mlx_string_put(all->data.mlx, all->data.win, 0,
		all->map->length * 50 + 10, 0xC0e6f0, string);
	free(string);
	string = NULL;
}
