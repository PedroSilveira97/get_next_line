/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptavares <ptavares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:31:20 by ptavares          #+#    #+#             */
/*   Updated: 2025/06/26 22:38:02 by ptavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

char	*ft_strchr(char *str, size_t c)
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	int		i;
	int		j;
	int		k;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	s3 = malloc((i + j + 1) * sizeof (char));
	if (!s3)
		return (NULL);
	k = 0;
	while (k < i)
		s3[k++] = *s1++;
	while (k < i + j)
		s3[k++] = *s2++;
	s3[k] = '\0';
	return (s3);
}

char	*ft_substr(char *str, size_t ii, size_t fi)
{
	char	*substr;
	size_t	i;

	if (!str)
		return (malloc(1));
	i = ft_strlen(str);
	if (ii > fi || ii >= i)
		return (malloc(1));
	if (fi >= i)
		fi = i - 1;
	substr = malloc((fi - ii + 2) * sizeof (char));
	if (!substr)
		return (NULL);
	i = 0;
	while (ii + i <= fi && str[ii + i])
		substr[i] = str[ii + i++];
	substr[i] = '\0';
	return (substr);
}
