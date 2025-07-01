/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptavares <ptavares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:00:45 by ptavares          #+#    #+#             */
/*   Updated: 2025/06/30 15:43:57 by ptavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_loop(int fd, char *line, char *buf)
{
	int		rd;
	char	*aux;

	while (1)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd < 0)
		{
			free(line);
			return (NULL);
		}
		buf[rd] = '\0';
		aux = ft_strjoin(line, buf);
		free(line);
		if (!aux)
			return (NULL);
		line = aux;
		if (ft_strchr(buf, '\n') || rd == 0)
			break ;
	}
	return (line);
}

static char	*ft_extract_line(char *stash)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = (char *)malloc(i + 1);
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

static char	*ft_load_line(char *buf, char *line)
{
	char	*stash;
	char	*final_line;

	stash = ft_strjoin(line, buf);
	free(line);
	if (!stash)
		return (NULL);
	final_line = ft_extract_line(stash);
	if (!final_line)
	{
		free(stash);
		return (NULL);
	}
	free(stash);
	ft_remainder(buf);
	return (final_line);
}

char	*ft_process_buf(char *buf, char *line, char **output)
{
	char	*aux;

	*output = NULL;
	if (buf[0] && ft_strchr(buf, '\n'))
	{
		aux = ft_load_line(buf, line);
		*output = aux;
		return (NULL);
	}
	else if (buf[0])
	{
		aux = ft_strjoin(line, buf);
		free(line);
		if (!aux)
			return (NULL);
		buf[0] = '\0';
		return (aux);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	char		*aux;
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	aux = ft_process_buf(buf, line, &ret);
	if (ret)
		return (ret);
	if (!aux)
		return (NULL);
	line = aux;
	line = ft_read_loop(fd, line, buf);
	if (!line || line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (ft_load_line(buf, line));
}
