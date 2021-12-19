/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:02:44 by ufitzhug          #+#    #+#             */
/*   Updated: 2021/12/18 18:02:50 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INC_03_GET_NEXT_LINE_GET_NEXT_LINE_H
# define INC_03_GET_NEXT_LINE_GET_NEXT_LINE_H
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char		*ft_strchr(const char *s, int ch);
char		*ft_read_text(int fd, char *buf, char *str_main);
static char	*ft_dest(char const *s1, char const *s2, char *dest);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *str);
char		*get_next_line(int fd);
char		*ft_get_one_line(char *main_str);
char		*ft_del_one_line(char *main_str);

#ifdefined BUFFER_SIZE
#if BUFFER_SIZE < 0
# undef BUFFER_SIZE
# define BUFFER_SIZE 0

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif



# endif
