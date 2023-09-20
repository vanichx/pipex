/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetruni <ipetruni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:40:07 by ipetruni          #+#    #+#             */
/*   Updated: 2023/09/20 13:23:44 by ipetruni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>//for malloc and free functions
# include <unistd.h>//for file I/O (read, write, open, close,)
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

// PRINCIPALES 
char	*get_next_line(int fd);

// UTILS
int		ft_clean(char *str);
size_t	ft_strlen(char *s);
char	*str_join(char *s1, char *s2);

#endif