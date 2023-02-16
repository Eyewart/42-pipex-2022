/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hassan <hrifi-la@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:18:50 by Hassan            #+#    #+#             */
/*   Updated: 2023/02/16 14:39:34 by Hassan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	size_tab(char const *string, char c)
{
	int	i;
	int	size;

	size = 0;
	i = 0;
	while (string && string[i])
	{
		while (string[i] == c)
			i++;
		if (string[i])
			size++;
		while (string[i] != c && string[i] != 0)
			i++;
	}
	return (size);
}

static char	*malloc_string(int len, char **tab_str, int j)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
	{
		while (i < j)
		{
			free(tab_str[i]);
			i++;
		}
		free(tab_str);
		return (0);
	}
	return (str);
}

int	malloc_tab(char ***tab_strings, char const *s, char c)
{
	*tab_strings = malloc(sizeof(*tab_strings) * (size_tab(s, c) + 1));
	if (!*tab_strings)
		return (0);
	return (1);
}

static char	**run_split(char const *s, char c, int i, char **tab_strings)
{
	int	str_l;
	int	k;
	int	j;

	j = 0;
	while (s && s[i])
	{
		while (s[i] == c)
			i++;
		str_l = 0;
		while (s[i + str_l] != c && s[i + str_l] != 0)
			str_l++;
		if (str_l == 0)
			break ;
		tab_strings[j] = malloc_string(str_l, tab_strings, j);
		if (!tab_strings[j])
			return (NULL);
		k = 0;
		while (k < str_l && str_l != 0)
			*(tab_strings[j] + k++) = s[i++];
		*(tab_strings[j] + k) = 0;
		j++;
	}
	tab_strings[j] = 0;
	return (tab_strings);
}

char	**ft_split(char const *s, char c)
{
	char	**tab_strings;

	tab_strings = 0;
	if (!s)
		return (NULL);
	if (!(malloc_tab(&tab_strings, s, c)))
		return (NULL);
	return (run_split(s, c, 0, tab_strings));
}
