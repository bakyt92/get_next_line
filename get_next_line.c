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

char *get_next_line(int fd)
{
	char		*buf;
	static char *str;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	while ()

}

int main (void)
{
	int fd;

	fd = open("text_test.txt", O_RDONLY);
	get_next_line(fd);
	return (0);
}

