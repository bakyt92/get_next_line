/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:02:30 by ufitzhug          #+#    #+#             */
/*   Updated: 2021/12/18 18:02:51 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int ch)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == (char)ch)
			return((char *)s);
		else s++;
	}
	if (*s == (char)ch)
		return((char *)s);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = (char *) malloc (1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * (ft_strlen((s1) +
													ft_strlen(s2) + 1)));
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		dest[i] = s2[j];
		j++;
		i++;
	}
	free(s1);
	dest[i] = '\0';
	return (dest);
}

//static char	*ft_dest(char const *s1, char const *s2, char *dest)
//{
//	size_t	len1;
//	size_t	len2;
//	size_t	i;
//
//	len1 = ft_strlen((char *)s1);
//	len2 = ft_strlen((char *)s2);
//	i = 0;
//	while (i < len1)
//	{
//		dest[i] = s1[i];
//		i++;
//	}
//	while (i < len2 + len1)
//	{
//		dest[i] = s2[i - len1];
//		i++;
//	}
//	dest[i] = '\0';
//	return (dest);
//}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
