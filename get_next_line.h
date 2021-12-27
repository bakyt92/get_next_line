/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:02:44 by ufitzhug          #+#    #+#             */
/*   Updated: 2021/12/26 20:21:06 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char		*ft_strdup(const char *s);
char		*ft_strchr(const char *s, int ch);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlen(const char *str);
char		*get_next_line(int fd);
char		*ft_get_one_line(char *main_str);
char		*ft_del_one_line(char *main_str);
char		*ft_line_write(char *line, char *main_str);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
#endif
