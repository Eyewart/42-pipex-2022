/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_fcts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hassan <hrifi-la@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:54:54 by Hassan            #+#    #+#             */
/*   Updated: 2023/02/16 14:40:00 by Hassan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

int	ft_strichr(char *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	if (s[i] == c)
		return (i);
	return (-1);
}

char	*ft_dirjoin(char const *s1, char const *s2)
{
	char	*str;
	int		t_size;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	t_size = ft_strlen(s1) + ft_strlen(s2) + 2;
	str = malloc(sizeof(*s1) * t_size);
	if (str == 0)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i++] = '/';
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*s1_1;
	unsigned char	*s2_2;

	i = 0;
	s1_1 = (unsigned char *)s1;
	s2_2 = (unsigned char *)s2;
	while ((s1_1[i] != 0 || s2_2[i] != 0) && i < n)
	{
		if (s1_1[i] != s2_2[i])
			return (s1_1[i] - s2_2[i]);
		i++;
	}
	return (0);
}

char	*ft_strndup(char *str1, int n)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = malloc(sizeof(char) * (n + 1));
	if (ptr == 0)
		return (0);
	while (i < n)
	{
		ptr[i] = str1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
