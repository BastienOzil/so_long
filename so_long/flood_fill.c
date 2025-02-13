/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:26:21 by bozil             #+#    #+#             */
/*   Updated: 2025/02/13 11:41:05 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void flood_fill_util(char **grid, int x, int y, t_map *map)
{
    if (x < 0 || x >= map->width || y < 0 || y >= map->height)
        return;
    if (grid[y][x] == '1' || grid[y][x] == 'F')
        return;

    grid[y][x] = 'F';
    flood_fill_util(grid, x + 1, y, map);
    flood_fill_util(grid, x - 1, y, map);
    flood_fill_util(grid, x, y + 1, map);
    flood_fill_util(grid, x, y - 1, map);
}

static char **copy_map_grid(t_map *map)
{
    char **copy;
    int y;

    copy = malloc(sizeof(char *) * map->height);
    if (!copy)
        return (NULL);
    y = 0;
    while (y < map->height)
    {
        copy[y] = ft_strdup(map->grid[y]);
        if (!copy[y])
        {
            while (--y >= 0)
                free(copy[y]);
            free(copy);
            return (NULL);
        }
        y++;
    }
    return (copy);
}

static int validate_grid_access(t_map *map, char **copy)
{
    int y;
    int x;

    y = 0;
    while (y < map->height)
    {
        x = 0;
        while (x < map->width)
        {
            if ((map->grid[y][x] == 'C' || map->grid[y][x] == 'E') && copy[y][x] != 'F')
                return (0);
            x++;
        }
        y++;
    }
    return (1);
}

int validate_accessibility(t_map *map)
{
    char **copy;
    int y;

    copy = copy_map_grid(map);
    if (!copy)
        return (0);
    flood_fill_util(copy, map->player_x, map->player_y, map);
    if (!validate_grid_access(map, copy))
    {
        y = 0;
        while (y < map->height)
            free(copy[y++]);
        free(copy);
        return (0);
    }
    y = 0;
    while (y < map->height)
        free(copy[y++]);
    free(copy);
    return (1);
}