/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetruni <ipetruni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:12:09 by ipetruni          #+#    #+#             */
/*   Updated: 2023/09/20 11:33:34 by ipetruni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*new_string;
	size_t	i;
	size_t	j;

	i = start;
	j = 0;
	if (start > ft_strlen(s))
		len = 0;
	else if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	new_string = malloc((len + 1) * sizeof(char));
	if (!s || !new_string)
		return (NULL);
	while (i < ft_strlen(s) && j < len && s[i] != '\0')
		new_string[j++] = s[i++];
	new_string[j] = '\0';
	return (new_string);
}