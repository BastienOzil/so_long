/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:50:30 by bozil             #+#    #+#             */
/*   Updated: 2025/02/13 10:35:19 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int is_valid_char(char c)
{
    return (c == '1' || c == '0' || c == 'C' || c == 'E' || c == 'P');
}

int check_map(t_map *map)
{
    int x;
    int y;

    map->collectibles = 0;
    map->exits = 0;
    map->player_start = 0;
    y = 0;
    while (y < map->height)
    {
        x = 0;
        while (map->grid[y][x])
        {
            if (!is_valid_char(map->grid[y][x]))
                return (0);
            if (map->grid[y][x] == 'C')
                map->collectibles++;
            if (map->grid[y][x] == 'E')
                map->exits++;
            if (map->grid[y][x] == 'P')
                map->player_start++;
            x++;
        }
        y++;
    }
    return (map->collectibles > 0 && map->exits == 1 && map->player_start == 1);
}
