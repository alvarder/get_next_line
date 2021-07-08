/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia- </var/mail/agarcia->              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 16:10:40 by agarcia-          #+#    #+#             */
/*   Updated: 2021/07/08 16:54:08 by agarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"
#include	<unistd.h>
#include	<stdlib.h>

void	ft_libsup(char **as)
{
	if (as)
	{
		free(*as);
		*as = NULL;
	}
}

char	*ft_strdup(const char *s1)
{
	int		a;
	char	*s2;

	a = ft_strlen(s1);
	s2 = malloc((a + 1) * sizeof(char));
	if (!s2)
		return (0);
	a = 0;
	while (s1[a] != '\0')
	{
		s2[a] = s1[a];
		a++;
	}
	s2[a] = '\0';
	return (s2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		a;
	int		b;

	a = 0;
	b = 0;
	if (!s1 || !s2)
		return (0);
	s3 = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s3)
		return (0);
	while (s1[a] != '\0')
		s3[b++] = s1[a++];
	a = 0;
	while (s2[a] != '\0')
		s3[b++] = s2[a++];
	s3[b] = '\0';
	return (s3);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	b;
	int		a;

	str = (char *)s;
	b = (char)c;
	a = 0;
	while (s[a] != '\0')
	{
		a++;
	}
	while (a >= 0)
	{
		if (s[a] == b)
			return (&str[a]);
		else
			a--;
	}
	if (b == '\0')
		return (&str[a]);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	a;
	unsigned int	b;

	a = 0;
	b = 0;
	(str = malloc(len + 1 * sizeof(char)));
	if (!s || !str)
		return (0);
	while (s[a])
	{
		if (a >= start && b < len)
		{
			str[b] = s[a];
			b++;
		}
		a++;
	}
	str[b] = '\0';
	return (str);
}
