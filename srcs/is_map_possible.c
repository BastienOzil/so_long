/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_possible.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:25:36 by bozil             #+#    #+#             */
/*   Updated: 2025/02/18 11:30:38 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	reset_visited(int *visited, t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			visited[y * map->width + x] = 0;
			x++;
		}
		y++;
	}
}

static void	fill_cell(int *visited, t_map *map, int x, int y)
{
	if (x < 0 || y < 0 || x >= map->width || y >= map->height)
		return ;
	if (map->grid[y][x] == '1' || visited[y * map->width + x])
		return ;
	visited[y * map->width + x] = 1;
	fill_cell(visited, map, x + 1, y);
	fill_cell(visited, map, x - 1, y);
	fill_cell(visited, map, x, y + 1);
	fill_cell(visited, map, x, y - 1);
}

static void	find_player_start(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] == 'P')
			{
				map->player_x = x;
				map->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
	ft_printf("Error:\nNo starting position 'P' found on the map.\n");
	exit(1);
}

static int	check_collectibles_and_exit(t_game *game, int *visited)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if ((game->map.grid[y][x] == 'C' || game->map.grid[y][x] == 'E')
				&& !visited[y * game->map.width + x])
			{
				free(visited);
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	is_map_possible(t_game *game)
{
	int	*visited;

	visited = malloc(game->map.width * game->map.height * sizeof(int));
	if (!visited)
	{
		ft_printf("Error:\nMemory allocation failed.\n");
		exit(1);
	}
	reset_visited(visited, &game->map);
	find_player_start(&game->map);
	fill_cell(visited, &game->map, game->map.player_x, game->map.player_y);
	if (!check_collectibles_and_exit(game, visited))
		return (0);
	free(visited);
	return (1);
}
