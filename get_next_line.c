/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 15:17:05 by eesaki            #+#    #+#             */
/*   Updated: 2020/04/25 19:29:20 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	cat_str(int fd, char **strs, char *buff)
{
	char	*tmp;

	tmp = ft_strjoin(strs[fd], buff);
	free(strs[fd]);
	strs[fd] = tmp;
}

int		get_line(char **str, char **line)
{
	char	*nl;
	char	*tmp;

	while ((nl = ft_strchr(*str, '\n')))
	{/* extract line from str, store it in line, udpate str */
		*line = ft_strndup(*str, (nl - *str));
		tmp = ft_strdup(nl + 1);
		free(*str);
		*str = tmp;
		return (1);
	}
	if (**str)
	{/* if \n wasn't found in str, store everything in line */
		*line = ft_strdup(*str);
		ft_bzero(*str, ft_strlen(*str));
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	static char	*s[FD_MAX];
	int			rc;

	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	while ((rc = read(fd, buff, BUFF_SIZE)) != 0)
	{/* read until EOF, create a str, store ptr to it in arr of ptrs */
		if (rc == -1)
			return (-1);
		buff[rc] = '\0';
		if (!s[fd])
			s[fd] = ft_strdup(buff);
		else
			cat_str(fd, &s[fd], buff);
		if (ft_strchr(s[fd], '\n'))
			return (get_line(&s[fd], line));
	}
	if (rc < 1 && s[fd] == NULL)
		return (rc);
	if (ft_strlen(s[fd]) > 0)
		return (get_line(&s[fd], line));
	return (0);
}
