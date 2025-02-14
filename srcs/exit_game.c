/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 08:47:13 by bozil             #+#    #+#             */
/*   Updated: 2025/02/14 11:27:07 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void exit_game(t_game *game)
{
    if (game->wall_img)
        mlx_destroy_image(game->mlx, game->wall_img);
    if (game->floor_img)
        mlx_destroy_image(game->mlx, game->floor_img);
    if (game->exit_img)
        mlx_destroy_image(game->mlx, game->exit_img);
    if (game->item_img)
        mlx_destroy_image(game->mlx, game->item_img);
    if (game->player_img)
        mlx_destroy_image(game->mlx, game->player_img);
    if (game->win)
        mlx_destroy_window(game->mlx, game->win);
    free_map(&game->map);
}
