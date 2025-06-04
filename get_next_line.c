/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptavares <ptavares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:26:18 by ptavares          #+#    #+#             */
/*   Updated: 2025/06/04 13:19:57 by ptavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*cleanup(char *buffer, char *leftover)
{
	free(buffer);
	free(leftover);
	return (NULL);
}

char	*read_file(int fd, char *leftover)
{
	char	*buffer;
	char	*aux;
	ssize_t	bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(leftover, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (cleanup(buffer, leftover));
		buffer[bytes] = '\0';
		aux = leftover;
		leftover = ft_strjoin(leftover, buffer);
		if (!leftover)
			return (cleanup(aux, buffer));
		free(aux);
	}
	free(buffer);
	return (leftover);
}

static char	*update_remainder(char *remainder)
{
	size_t	i;
	char	*new_remainder;

	i = 0;
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (!remainder[i])
	{
		free(remainder);
		return (NULL);
	}
	new_remainder = ft_strdup(remainder + i + 1);
	free(remainder);
	return (new_remainder);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	leftover = read_file(fd, leftover);
	if (!leftover)
		return (NULL);
	line = ft_get_line(leftover);
	leftover = update_remainder(leftover);
	return (line);
}
