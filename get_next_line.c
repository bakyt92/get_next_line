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
#include <stdio.h>

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
		main_str = NULL;
		return (NULL);
	}
	temp = (char *) malloc(sizeof(char) * (ft_strlen(main_str) - i + 1));
	if (!temp)
		return(NULL);
	i++;
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
//	static int 	leaks_line;

	line = NULL;
	i = 0;
	if(!main_str[i])
		return (NULL);
	while (main_str[i] && main_str[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2)); /* добавил +2, т.к. есть
 * знак конца строки */
//	printf("leaks_line %d\t", leaks_line++);
	if (!line)
		return(NULL);
	i = 0;
	while (main_str[i] && main_str[i] != '\n')
	{
		line[i] = main_str[i];
		i++;
	}
	if (main_str[i] == '\n')
		line[i] = main_str[i];
	else
		line[i] = '\0';
	i++;
	line[i] = '\0';
	return(line);
}

char	*ft_read_text(int fd, char *str_main)
{
	ssize_t	byte_read;
	char 	buf[BUFFER_SIZE + 1];
//	char	*temp;

//	printf("strmain = %s \t", str_main);
	byte_read = 1;
	while(!ft_strchr(str_main, '\n') && byte_read != 0 && str_main)
	{
//		printf("while numbet \t");
		byte_read = read(fd, buf, BUFFER_SIZE);
		if (byte_read == -1)
		{
//			printf("check byte read = -1");
			free(str_main);
			return (NULL);
		}
//			return (0);
//		printf("check byte read = -4\t");
		buf[byte_read] = '\0';
//		temp = (char *)malloc((ft_strlen(str_main) + 1) * sizeof(char));
//		if (!temp)
//			return(NULL);

//		printf("\n before strjoin1 \n");
//		printf(" check3str_main = %s \n", str_main);
//		printf("\n buf = %s \n", buf);
//		temp = str_main;
		str_main = ft_strjoin(&str_main, buf);
//		free(buf);
//		buf[0] = ((void *)0);
//		str_main = ft_strdup(temp);
//		free(temp);
//		printf(" check4str_main = %s \n", str_main);
//		printf("\n after strjoin2 \n");
	}
	return (str_main);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char *str_main;
//	char		*res;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
//	if (str_main)
//	{
//		res = ft_strdup(str_main);
//		free(str_main);
//		str_main = NULL;
//	}
	if (!str_main)
		str_main = ft_strdup("");
//	line = ft_strdup("");


//	if (read(fd, line, 0) < 0)
//		return (NULL);
//	printf(" check1 \n");
	str_main = ft_read_text(fd, str_main);
//	printf(" check2 %s\n ", str_main);
	if (!str_main)
		return (NULL);
//	printf("str_main_bef %s\n", str_main);
	line = ft_get_one_line(str_main);
	if (!line)
		return (NULL);
	str_main = ft_del_one_line(str_main);
//	printf("str_main_aft %s\n", str_main);

	return (line);
}

int	main (void)
{
	int fd;
	char *line;
	int iter;

	iter = 50;

//	line = ft_strdup("");
	line = "";

	fd = open("41_no_nl", O_RDONLY);
	printf("fd after = %d \n", fd);
//	printf("%d", fd);
	while (iter--)
	{
//		printf("\t iter = %d \t", iter);
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			break;
		}
		printf("%s", line);
		free (line);
		line = NULL;
	}

//	while (line)
//	{

//
//	}
//	line = get_next_line(fd);
//	printf(" main_1 %s \n", line);
//	free (line);
//	line = get_next_line(fd);
//	printf(" main_2 %s \n", line);
//	free (line);
//printf("main_1 %s" ,get_next_line(fd));
//	printf("main_2 %s" ,get_next_line(fd));
//	printf("%s" ,get_next_line(fd));
//	printf("%s" ,get_next_line(fd));
	close(fd);
	free (line);
	line = NULL;

	return (0);
}
