/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 15:17:05 by eesaki            #+#    #+#             */
/*   Updated: 2019/05/03 16:34: by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

int		get_line(char **str, char **line)
{
	char	*nl;
	char	*tmp;

	while ((nl = ft_strchr(*str, '\n'))) // while there's a \n
	{
		*line = ft_strndup(*str, (nl - *str)); // dup first line
		tmp = ft_strdup(nl + 1); // assing next starting pos to tmp (must dup because otherwise, in next loop, *str is not malloced, thus cannot be freed)
		free(*str); // *str is unnecesary because next starting pos is stored on tmp
		*str = tmp; // assing next starting pos to *str
		return (1); // read
	}
	if (**str) // \n not found, **str is not NULL
	{
		*line = ft_strdup(*str); // *line = p->(all read data)
		ft_bzero(*str, ft_strlen(*str)); // 0 out *str so that get_line will not be called anymore (because EOF)
		return (1); // read
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	static char	*s[FD_MAX]; // store ptr to read data. data from different fds are stored on individual elements of *s[]
	char		*tmp;
	int			rc; // num of bytes read from fd

	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	while ((rc = read(fd, buff, BUFF_SIZE)) != 0) // while there's something that has been read
	{
		if (rc == -1) // read() error handling
			return (-1);
		buff[rc] = '\0'; // null terminate read string stored on buff
		if (!s[fd]) // first time to assign read data to s[fd]?
			s[fd] = ft_strdup(buff); // dup buff
		else // not first time to assign read data to s[fd]
		{
			tmp = ft_strjoin(s[fd], buff); 
			free(s[fd]); // freeing s[fd] = ft_strdup(buff);
			s[fd] = tmp; // assigin cat-ed string
		}
	}
	if (ft_strlen(s[fd]) > 0) // more lines remaining?
		return (get_line(&s[fd], line)); // find next line and store it on line
	return (0);
}