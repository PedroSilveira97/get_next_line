/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptavares <ptavares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:41:25 by ptavares          #+#    #+#             */
/*   Updated: 2025/06/27 13:29:13 by ptavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

size_t		ft_strlen(char *str);
char		*ft_strchr(char *str, size_t c);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_substr(char *str, ssize_t ii, size_t fi);
char		*get_next_line(int fd);
static char	*extract_line(char **sth);
static char	*read_to_stash(int fd, char *stash);
static char	*ft_free_all(char *s1, char *s2);

#endif
