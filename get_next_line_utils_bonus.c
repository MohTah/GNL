/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msadaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 15:36:32 by msadaoui          #+#    #+#             */
/*   Updated: 2021/05/06 15:41:05 by msadaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	size;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(*str) * (size + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

void	ft_strdel(char **as)
{
	if (!(as && *as))
		return ;
	free(*as);
	*as = NULL;
}

char	*ft_strchr(const char *str, int c)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)c)
			return ((char *)str + i);
		i++;
	}
	if (str[i] == (unsigned char)c)
		return ((char *)str + i);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		j;
	char	*dest;

	j = 0;
	while (s[j] != '\0')
		j++;
	dest = malloc(sizeof(*dest) * j + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (i < j)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
