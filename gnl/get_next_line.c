/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetruni <ipetruni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:26:12 by ipetruni          #+#    #+#             */
/*   Updated: 2023/09/20 13:23:31 by ipetruni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	line[BUFFER_SIZE + 1];
	char		*next_line;
	int			i;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	next_line = str_join(0, line);
	if (ft_clean(line) > 0)
		return (next_line);
	i = read(fd, line, BUFFER_SIZE);
	if (i < 0)
	{
		free(next_line);
		next_line = NULL;
		return (NULL);
	}
	while (i > 0)
	{
		next_line = str_join(next_line, line);
		if (ft_clean(line) > 0)
			break ;
		i = read(fd, line, BUFFER_SIZE);
	}
	return (next_line);
}
