/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 09:22:04 by bozil             #+#    #+#             */
/*   Updated: 2025/02/14 11:27:45 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void render_map(t_game *game)
{
    int x;
    int y;

    y = 0;
    while (y < game->map.height)
    {
        x = 0;
        while (x < game->map.width)
        {
            if (game->map.grid[y][x] == '1')
                mlx_put_image_to_window(game->mlx, game->win, game->wall_img, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map.grid[y][x] == '0')
                mlx_put_image_to_window(game->mlx, game->win, game->floor_img, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map.grid[y][x] == 'C')
                mlx_put_image_to_window(game->mlx, game->win, game->item_img, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map.grid[y][x] == 'E')
                mlx_put_image_to_window(game->mlx, game->win, game->exit_img, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map.grid[y][x] == 'P')
                mlx_put_image_to_window(game->mlx, game->win, game->player_img, x * TILE_SIZE, y * TILE_SIZE);
            x++;
        }
        y++;
    }
}