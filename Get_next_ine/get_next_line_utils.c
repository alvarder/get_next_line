#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t a;

	a = 0;
	while (s[a] != '\0')
	{
		a++;
	}
	return (a);
}

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
	if (!(s2 = malloc((a + 1) * sizeof(char))))
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
	if (!(s3 = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char))))
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
	if (!s || !(str = malloc(len + 1 * sizeof(char))))
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
 
