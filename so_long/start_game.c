/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:30:25 by bozil             #+#    #+#             */
/*   Updated: 2025/02/13 11:08:46 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void find_player_start(t_game *game)
{
    int y;
    int x;

    y = 0;
    while (y < game->map.height)
    {
        x = 0;
        while (x < game->map.width)
        {
            if (game->map.grid[y][x] == 'P')
            {
                game->player_x = x;
                game->player_y = y;
                return;
            }
            x++;
        }
        y++;
    }
    ft_printf("Error: No starting position 'P' found on the map.\n");
    exit_game(game);
    exit(1);
}

void start_game(t_game *game)
{
    game->mlx = mlx_init();
    if (!game->mlx)
    {
        ft_printf("Error: Failed to initialize mlx\n");
        exit(1);
    }
    game->win = mlx_new_window(game->mlx, game->map.width * TILE_SIZE, game->map.height * TILE_SIZE, "so_long");
    if (!game->win)
    {
        ft_printf("Error: Failed to create window\n");
        exit(1);
    }
    find_player_start(game);
    load_textures(game);
    render_map(game);
    mlx_key_hook(game->win, key_press, game);
    mlx_loop(game->mlx);
}
