/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:50:30 by bozil             #+#    #+#             */
/*   Updated: 2025/02/18 11:33:15 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	is_valid_char(char c)
{
	return (c == '1' || c == '0' || c == 'C' || c == 'E' || c == 'P');
}

static void	initialize_map_elements(t_map *map)
{
	map->collectibles = 0;
	map->exits = 0;
	map->player_start = 0;
}

static int	process_map_cell(t_map *map, int y, int x)
{
	if (!is_valid_char(map->grid[y][x]))
		return (0);
	if (map->grid[y][x] == 'C')
		map->collectibles++;
	if (map->grid[y][x] == 'E')
		map->exits++;
	if (map->grid[y][x] == 'P')
		map->player_start++;
	return (1);
}

static int	parse_map_grid(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (map->grid[y][x])
		{
			if (!process_map_cell(map, y, x))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	check_map(t_map *map)
{
	initialize_map_elements(map);
	if (!is_rectangular(map))
	{
		/*ft_printf("Error:\nMap is not rectangular.\n");*/
		return (0);
	}
	if (!is_surrounded_by_walls(map))
	{
		/*ft_printf("Error:\nMap is not surrounded by walls.\n");*/
		return (0);
	}
	if (!parse_map_grid(map))
	{
		/*ft_printf("Error:\nInvalid characters in map or invalid configuration.\n");*/
		return (0);
	}
	return (map->collectibles > 0 && map->exits == 1 && map->player_start == 1);
}
