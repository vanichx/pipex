/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetruni <ipetruni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:12:48 by ipetruni          #+#    #+#             */
/*   Updated: 2023/09/20 15:04:15 by ipetruni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	wcounter(char const *str, char c)
{
	int	counter;
	int	trigger;

	counter = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			counter++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (counter);
}

static void	*free_function(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

static char	**get_string(char *s, char c, int index, char **split)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = ft_substr(s, index, i - index);
			if (!split[j - 1])
			{
				free_function(split);
				return (NULL);
			}
			index = -1;
		}
		i++;
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		index;
	char	**split;

	i = wcounter(s, c);
	index = -1;
	split = (char **)malloc((i + 1) * sizeof(char *));
	if (!s || !split)
		return (NULL);
	split = get_string(s, c, index, split);
	if (!split)
		return (NULL);
	return (split);
}
