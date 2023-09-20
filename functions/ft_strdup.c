/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetruni <ipetruni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:55:58 by ipetruni          #+#    #+#             */
/*   Updated: 2023/09/20 11:34:09 by ipetruni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_strdup(char *src)
{
	char	*new;
	int		buf_size;

	buf_size = ft_strlen(src) + 1;
	new = malloc(buf_size);
	if (NULL == new)
		return (NULL);
	ft_strlcpy(new, src, buf_size);
	return (new);
}
