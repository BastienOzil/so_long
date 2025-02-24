/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:43:22 by bozil             #+#    #+#             */
/*   Updated: 2025/02/24 11:29:36 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../utils/ft_printf/ft_printf.h"
# include "../utils/get_next_line/get_next_line.h"
# include "../utils/libft/libft.h"
# include "keymap.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define TILE_SIZE 64

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		collectibles;
	int		exits;
	int		player_start;
	int		player_x;
	int		player_y;
}			t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	map;
	int		player_x;
	int		player_y;
	int		moves;
	void	*wall_img;
	void	*floor_img;
	void	*exit_img;
	void	*item_img;
	void	*player_img;
}			t_game;

int			key_press(int key, t_game *game);
int			check_map(t_map *map);
int			parse_map(const char *file, t_map *map);
int			is_map_possible(t_game *game);
int			is_surrounded_by_walls(t_map *map);
int			is_rectangular(t_map *map);
void		start_game(t_game *game);
void		render_map(t_game *game);
void		render_map2(t_game *game);
void		free_map(t_map *map);
void		load_textures(t_game *game);
void		exit_game(t_game *game);

#endif
