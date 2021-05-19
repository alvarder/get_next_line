/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 17:29:42 by agarcia-          #+#    #+#             */
/*   Updated: 2021/05/19 17:49:23 by agarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
