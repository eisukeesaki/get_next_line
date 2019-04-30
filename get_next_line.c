/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 15:17:05 by eesaki            #+#    #+#             */
/*   Updated: 2019/04/29 20:26:33 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<test purpose
#include <stdio.h>
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>test purpose

int		get_line(char **str, char **line)
{
	char	*nl;

	if (*str)
	{
		nl = ft_strchr(*str, '\n');
		if (nl != *str)
		{
			*line = strndup(*str, (nl - *str)); // create own strndup
			*str = nl + 1;
		}
		else
		{
			*line = ft_strnew(0);
			*str = nl + 1;
			return (1);
		}
	}
	if (ft_strlen(*line) > 0)
		return (1);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int			rc;
	char		buff[BUFF_SIZE + 1];
	static char	*s[FD_MAX];
	char		*tmp;

	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	while ((rc = read(fd, buff, BUFF_SIZE)) != 0)
	{
		if (rc == -1)
			return (-1);
		buff[rc] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(s[fd], buff);
			free(s[fd]);
			s[fd] = tmp;
		}
	}
	if (ft_strlen(s[fd]) > 0)
		return (get_line(&s[fd], line));
	return (0);
}

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<test purpose
// int		main(int ac, char **av)
// {
// 	int		fd;
// 	char	*line = NULL;
	
// 	if (ac == 1)
// 		fd = 0;
// 	else if (ac == 2)
// 		fd = open(av[1], O_RDONLY);
// 	else
// 		return (-1);

// 	while (get_next_line(fd, &line))
// 		printf("line:%s\n", line);

// 	return (0);
// }
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>test purpose
