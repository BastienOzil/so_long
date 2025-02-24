/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:16:38 by bozil             #+#    #+#             */
/*   Updated: 2025/02/24 12:05:06 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_top_and_bottom(t_map *map)
{
	if (ft_strchr(map->grid[0], '0') || ft_strchr(map->grid[map->height - 1],
			'0'))
		return (0);
	return (1);
}

int	check_sides(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		if (map->grid[i][0] != '1' || map->grid[i][map->width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	is_surrounded_by_walls(t_map *map)
{
	if (!check_top_and_bottom(map) || !check_sides(map))
		return (0);
	return (1);
}

int	is_rectangular(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		if ((int)ft_strlen(map->grid[i]) != map->width)
			return (0);
		i++;
	}
	return (1);
}
