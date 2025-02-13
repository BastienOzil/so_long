/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:40:32 by bozil             #+#    #+#             */
/*   Updated: 2025/02/12 10:24:50 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    t_game game;

    if (argc != 2)
    {
        ft_printf("Usage: ./so_long <map_file.ber>\n");
        return (1);
    }
    if (!parse_map(argv[1], &game.map))
    {
        ft_printf("Error:\nInvalid map\n");
        return (1);
    }
    game.moves = 0;
    game.player_x = 0;
    game.player_y = 0;
    start_game(&game);
    exit_game(&game);
    return (0);
}
