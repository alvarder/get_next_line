/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 16:37:48 by agarcia-          #+#    #+#             */
/*   Updated: 2021/05/19 17:48:57 by agarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
