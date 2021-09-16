/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 03:35:07 by agarcia-          #+#    #+#             */
/*   Updated: 2021/09/16 05:33:29 by agarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*cleaner(char *line)
{
	free (line);
	return (NULL);
}

int	seleccionar(char *sta, char **line)
{
	char	*aux;
	char	*line2;
	char	buff[BUFFER_SIZE + 1];

	ft_bzero(buff, BUFFER_SIZE);
	aux = ft_strchr(sta, '\n');
	line2 = *line;
	if (aux)
	{
		*aux = '\0';
		*line = ft_strjoin(line2, sta);
		free (line2);
		ft_bzero(sta, BUFFER_SIZE + 1);
		ft_memcpy(sta, buff, ft_strlen(buff));
		ft_bzero(buff, BUFFER_SIZE + 1);
		line2 = *line;
		*line = ft_strjoin(line2, "\n");
		free (line2);
		return (1);
	}
	*line = ft_strjoin(line2, sta);
	free (line2);
	ft_bzero(sta, BUFFER_SIZE + 1);
	return (0);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	sta[256][BUFFER_SIZE + 1];
	int			a;

	line = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (fd < 0 || fd > 256 || BUFFER_SIZE <= 0 || !line)
		return (cleaner (line));
	ft_bzero(line, BUFFER_SIZE + 1);
	if (seleccionar (sta[fd], &line))
		return (line);
	a = read(fd, sta[fd], BUFFER_SIZE);
	while (a)
	{
		if (seleccionar(sta[fd], &line))
			return (line);
		else if (a == -1)
			return (cleaner (line));
		a = read(fd, sta[fd], BUFFER_SIZE);
	}
	if (line[0] == '\0')
		return (cleaner (line));
	return (line);
}
