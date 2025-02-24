/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:47:43 by bozil             #+#    #+#             */
/*   Updated: 2025/02/24 11:34:12 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	is_walkable(char tile, t_game *game)
{
	if (tile == 'E' && game->map.collectibles > 0)
		return (0);
	return (tile == '0' || tile == 'C' || tile == 'E');
}

static int	is_within_bounds(t_map *map, int x, int y)
{
	return (x >= 0 && x < map->width && y >= 0 && y < map->height);
}

static void	move_player(t_game *game, int new_x, int new_y)
{
	if (!is_within_bounds(&game->map, new_x, new_y))
		return ;
	if (!is_walkable(game->map.grid[new_y][new_x], game))
		return ;
	if (game->map.grid[new_y][new_x] == 'C')
		game->map.collectibles--;
	if (game->map.grid[new_y][new_x] == 'E' && game->map.collectibles == 0)
	{
		ft_printf("Congratulations!\nYou've won in %d moves!\n", game->moves);
		exit_game(game);
		exit(0);
	}
	game->map.grid[game->player_y][game->player_x] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	game->map.grid[game->player_y][game->player_x] = 'P';
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	render_map(game);
}

int	key_press(int key, t_game *game)
{
	if (key == KEY_ESC || key == CLOSE_BTN)
	{
		exit_game(game);
		exit(0);
	}
	if (key == KEY_W || key == KEY_UP)
		move_player(game, game->player_x, game->player_y - 1);
	else if (key == KEY_A || key == KEY_LEFT)
		move_player(game, game->player_x - 1, game->player_y);
	else if (key == KEY_S || key == KEY_DOWN)
		move_player(game, game->player_x, game->player_y + 1);
	else if (key == KEY_D || key == KEY_RIGHT)
		move_player(game, game->player_x + 1, game->player_y);
	return (0);
}
