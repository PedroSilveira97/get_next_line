/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptavares <ptavares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 23:00:22 by ptavares          #+#    #+#             */
/*   Updated: 2025/06/04 14:05:53 by ptavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (NULL);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;
	char	*s3;

	i = 0;
	j = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	s3 = malloc(len1 + len2 + 1);
	if (!s3)
		return (NULL);
	if (s1)
		while (s1[j])
			s3[i++] = s1[j++];
	j = 0;
	if (s2)
		while (s2[j])
			s3[i++] = s2[j++];
	s3[i] = '\0';
	return (s3);
}

char	*ft_strdup(const char *str)
{
	char	*s;
	char	*aux;

	s = malloc((ft_strlen(str) + 1) * sizeof (char));
	if (!s)
		return (NULL);
	aux = s;
	while (*str)
		*aux++ = *str++;
	*aux = '\0';
	return (s);
}

char	*ft_get_line(char	*str)
{
	char	*s;
	size_t	i;

	i = 0;
	if (!str || !*str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	s = malloc((i + 2) * sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		s[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
