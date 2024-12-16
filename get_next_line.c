/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:20:28 by gmorelli          #+#    #+#             */
/*   Updated: 2022/11/10 10:20:30 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_join_line(char *buf, char *tmp)
{
	char	*newbuf;

	newbuf = ft_strjoin(buf, tmp);
	free(buf);
	return (newbuf);
}

static char	*ft_reader(int fd, char *buf)
{
	int		line;
	char	*tmp;

	line = 1;
	tmp = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (buf == 0)
		buf = ft_calloc(1, 1);
	while (line > 0)
	{
		if (ft_strchr(buf, '\n'))
			break ;
		line = read(fd, tmp, BUFFER_SIZE);
		if (line < 0)
		{
			free(tmp);
			return (0);
		}
		tmp[line] = '\0';
		buf = ft_join_line(buf, tmp);
	}
	free (tmp);
	return (buf);
}

static char	*ft_strret(char *buf)
{
	int		i;
	char	*str;

	i = 0;
	if (!buf[i])
		return (0);
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	if (buf[i] == '\n')
		i++;
	str = ft_calloc(i + 1, sizeof(char));
	i = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
	{
		str[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
		str[i] = '\n';
	return (str);
}

static char	*ft_leftovers(char *buf)
{
	int		i;
	int		y;
	char	*str;

	i = 0;
	y = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	if (!buf[i])
	{
		free(buf);
		return (0);
	}
	str = ft_calloc((ft_strlen(buf) - i + 1), sizeof(char));
	i++;
	while (buf[i] != '\0')
	{
		str[y] = buf[i];
		y++;
		i++;
	}
	free (buf);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buf = ft_reader(fd, buf);
	ret = ft_strret(buf);
	buf = ft_leftovers(buf);
	return (ret);
}

int main()
{
	int fd;
	char *line;

	fd = open("boh.txt", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("%s\n", line);
		free(line);
	}
	return (0);
}