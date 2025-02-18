/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:07:10 by bozil             #+#    #+#             */
/*   Updated: 2025/02/18 11:21:21 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

/* int main(void); */
size_t	ft_strlen3(const char *s);
char	*get_next_line(int fd);
char	*ft_strjoin2(char *s1, char *s2);
char	*ft_strchr2(const char *s, int c);
char	*ft_substr2(char const *s, unsigned int start, size_t len);

#endif
