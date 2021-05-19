/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:42:35 by agarcia-          #+#    #+#             */
/*   Updated: 2021/05/19 17:46:53 by agarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h" 

int lineas(char **sta, char **line)
{
	int a;
	char *tmp;

	a = 0;
	while((*sta)[a] != '\n' && (*sta)[a] != '\0')
		a++;
	if ((*sta)[a] == '\n')
	{
		*line = ft_substr(*sta, 0, a);
		tmp = ft_strdup(&((*sta)[a + 1]));
		free (*sta);
		*sta = tmp;
		if ((*sta)[0] == '\0')
			free(sta);
	}
	else
	{
		*line = ft_strdup(*sta);
		//limpiar(sta)
	}
	return (1);
}

int	salida(char **sta, char **line, int a, int fd)
{
	if (a < 0)
		return (-1);
	else if (a == 0 && sta[fd] == NULL)
		return (0);
	else
		return (lineas(&sta[fd], line));
} 


int	get_next_line(int fd, char **line)
{
	int a;
	char *temp;
	static char *sta[4096];
	char buff[BUFF_SIZE + 1];

	if (fd < 0)
		return(-1);
	while((a = read (fd, buff, BUFF_SIZE)) > 0)
	{
		buff[a] = 0;
		if (sta[fd] == NULL)
			sta[fd] = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(sta[fd] ,buff);
			free(sta[fd]);
			sta[fd] = temp;
		}
		if (ft_strrchr(sta[fd], '\n'))
			break;
	}
	return(salida(sta, line, a, fd));
}

int main()
{
	int fd;
	char **line = NULL;
	
	fd = open("texto.txt", O_RDONLY);
	get_next_line(fd , line);
}
