/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:02:22 by ufitzhug          #+#    #+#             */
/*   Updated: 2021/12/18 18:02:52 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_del_one_line(char *main_str)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (main_str[i] && main_str[i] != '\n')
		i++;
	if(!main_str[i])
	{
		free(main_str);
		return (NULL);
	}
	temp = (char *)malloc(sizeof(char) * (ft_strlen(main_str) - i + 1));
	if (!temp)
		return(NULL);
	j = 0;
	while (main_str[i])
		temp[j++] = main_str[i++];
	temp[j] = '\0';
	free(main_str);
	return (temp);
}

char	*ft_get_one_line(char *main_str)
{
	int		i;
	char 	*line;

	i = 0;
	if(!main_str[i])
		return (NULL);
	while (main_str[i] && main_str[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return(NULL);
	i = 0;
	while (main_str[i] && main_str[i] != '\n')
	{
		line[i] = main_str[i];
		i++;
	}
	if (main_str[i] == '\n')
	{
		line[i] = main_str[i];
		i++;
	}
	return(line);
}

char	*ft_read_text(int fd, char *buf, char *str_main)
{
	int	byte_read;

	byte_read = 1;
	while(!ft_strchr(str_main, '\n') && byte_read != 0)
	{
		byte_read = read(fd, buf, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buf);
			return (0);
		}
		buf[byte_read] = '\0';
		str_main = ft_strjoin(str_main, buf);
	}
	free(buf);
	return (str_main);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char *str_main;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (0);
	str_main = ft_read_text(fd, buf, str_main);
	if (!str_main)
		return (NULL);
	line = ft_get_one_line(str_main);
	str_main = ft_del_one_line(str_main);
	return (line);
}

int	main (void)
{
	int fd;

	fd = open("test_text.txt", O_RDONLY);
	get_next_line(fd);
	return (0);
}

