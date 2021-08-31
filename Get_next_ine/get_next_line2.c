#include "get_next_line.h"

size_t  ft_strlen(const char *s)
{       
        size_t  a;
        
        a = 0;
        while (s[a] != '\0')
        {       
                a++;
        }
        return (a);
}

char     *lineas(char **sta)
{       
        int             a;
        char    	*tmp;
	char		*line;
        
        a = 0;
        while ((*sta)[a] != '\n' && (*sta)[a] != '\0')
                a++;
        if ((*sta)[a] == '\n')
        {       
                line = ft_substr(*sta, 0, a);
                tmp = ft_strdup(&(*sta)[a + 1]);
		free(*sta);
                *sta = tmp;
		if ((*sta)[0] == '\0')
			ft_libsup(&(*sta));
        }
        else    
        {       
                line = ft_strdup(*sta);
                ft_libsup(&(*sta));
                return (line);
        }
        return (line);
}

char	*get_next_line2(int fd)
{
	int		a;
	char		*linea;
	char		*temp;
	static char	*sta[4096];
	char		buff[BUFF_SIZE + 1];

	if (fd < 0 || BUFF_SIZE < 1 )
		return (0);
	a = read (fd, buff, BUFF_SIZE);
	while (a > 0)
	{
		buff[a] = 0;
		if (sta[fd] == NULL)
			sta[fd] = ft_strdup(buff);
		temp = ft_strjoin(sta[fd], buff);
		free(sta[fd]);
		sta[fd] = temp;
		if (ft_strrchr(sta[fd], '\n'))
			break;
		a = read (fd, buff, BUFF_SIZE);
	}
	return (lineas(&sta[fd]));
}

int main()
{
	int fd;
	char *line;
	int a;
	fd = open("txt.txt", O_RDONLY);
	while (a < 50)
	{
		printf("%s\n", get_next_line2(fd));
		a++;
	}
	system("leaks a.out");
}
