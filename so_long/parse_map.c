/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:47:20 by bozil             #+#    #+#             */
/*   Updated: 2025/02/13 11:27:28 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int is_valid_extension(const char *filename)
{
    size_t len = ft_strlen(filename);
    if (len < 4 || ft_strcmp(&filename[len - 4], ".ber") != 0)
        return (0);
    return (1);
}

static int read_map_file(const char *file, char **content)
{
    int fd;
    char *line;
    char *temp;

    *content = ft_strdup("");
    if (!*content)
        return (0);
    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (0);
    while ((line = get_next_line(fd)))
    {
        temp = ft_strjoin(*content, line);
        free(*content);
        free(line);
        if (!temp)
        {
            close(fd);
            return (0);
        }
        *content = temp;
    }
    close(fd);
    return (1);
}

static int convert_to_grid(t_map *map, const char *content)
{
    map->grid = ft_split(content, '\n');
    if (!map->grid)
        return (0);
    map->height = 0;
    while (map->grid[map->height])
        map->height++;
    map->width = ft_strlen(map->grid[0]);
    return (1);
}

int parse_map(const char *file, t_map *map)
{
    char *content;

    if (!is_valid_extension(file))
        return (0);
    if (!read_map_file(file, &content))
        return (0);
    if (!convert_to_grid(map, content))
    {
        free(content);
        return (0);
    }
    free(content);
    if (!check_map(map))
    {
        free_map(map);
        return (0);
    }
    if (!validate_accessibility(map))
    {
        ft_printf("Error: Not all 'C' or 'E' are reachable from 'P'.\n");
        free_map(map);
        return (0);
    }
    return (1);
}
