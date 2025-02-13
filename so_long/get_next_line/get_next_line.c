/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:07:20 by bozil             #+#    #+#             */
/*   Updated: 2025/02/12 10:43:51 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Extract the line from the static buffer */
static char	*extract_line(char **res)
{
	char	*line;
	char	*newline;
	char	*temp;

	if (!*res)
		return (NULL);
	newline = ft_strchr(*res, '\n');
	if (!newline)
	{
		line = *res;
		*res = NULL;
		return (line);
	}
	line = ft_substr2(*res, 0, newline - *res + 1);
	temp = ft_substr2(*res, newline - *res + 1, ft_strlen3(newline + 1));
	free(*res);
	*res = temp;
	return (line);
}

/* Read from file descriptor and update buffer */
static char	*read_buffer(int fd, char *res)
{
	char	*buffer;
	int		read_bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			free(buffer);
			free(res);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		res = ft_strjoin2(res, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*res = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	res = read_buffer(fd, res);
	if (!res || res[0] == '\0')
		return (NULL);
	line = extract_line(&res);
	return (line);
}
/*
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Erreur d'ouverture du fichier");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Ligne lue : %s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}*/
