/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 08:39:48 by bozil             #+#    #+#             */
/*   Updated: 2025/02/17 11:25:15 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_textures(t_game *game)
{
	int	img_width;
	int	img_height;

	game->wall_img = mlx_xpm_file_to_image(game->mlx, "elements/wall.xpm",
			&img_width, &img_height);
	game->floor_img = mlx_xpm_file_to_image(game->mlx, "elements/floor.xpm",
			&img_width, &img_height);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, "elements/exit.xpm",
			&img_width, &img_height);
	game->item_img = mlx_xpm_file_to_image(game->mlx, "elements/item.xpm",
			&img_width, &img_height);
	game->player_img = mlx_xpm_file_to_image(game->mlx, "elements/player.xpm",
			&img_width, &img_height);
	if (!game->wall_img || !game->floor_img || !game->exit_img
		|| !game->item_img || !game->player_img)
	{
		ft_printf("Error:\n Failed to load textures\n");
		exit(1);
	}
}
