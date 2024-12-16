/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:03:16 by gmorelli          #+#    #+#             */
/*   Updated: 2022/11/21 18:07:34 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*p;

	p = (char *)s;
	while (n > 0)
	{
		p[n - 1] = c;
		n--;
	}
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*p;

	i = nmemb * size;
	p = malloc(i);
	if (p == NULL)
		return (NULL);
	else
		ft_memset(p, '\0', i);
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str || !s1 || !s2)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	*p;
	int		i;

	i = 0;
	p = (char *) s;
	while (p[i])
	{
		if (p[i] == c)
			return (&p[i]);
		i++;
	}
	if (c == '\0')
		return (&p[i]);
	return (0);
}
