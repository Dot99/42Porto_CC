/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 08:59:40 by gude-jes          #+#    #+#             */
/*   Updated: 2024/05/10 12:50:17 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup mandatory Mandatory
 * @{
 * @file get_next_line.h
 * @brief Get Next Line Header Bonus
*/

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

char	*ft_strchr(char *str, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strndup(char *s, int len);
char	*free_data(char *stash, char *buffer);
char	*read_from_file(int fd, char *stash);
char	*leftovers(char *stash);
char	*get_next_line(int fd);

int		ft_strclen(char *str, char c);

#endif

/**@}*/