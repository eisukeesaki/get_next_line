/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 15:17:05 by eesaki            #+#    #+#             */
/*   Updated: 2019/04/27 19:44:49 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<test purpose
#include <stdio.h>
#include <fcntl.h>
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>test purpose

int		get_line(char *str, char **line)
{
	char	*tmp;
	char	*nl;

	nl = ft_strchr(str, '\n');
	*line = strndup(str, (nl - str)); // create own strndup

}

// read from fd, copy data to new malloced space
int		get_next_line(const int fd, char **line)
{
	int		rc;
	char	buff[BUFF_SIZE + 1];
	char	*s[FD_MAX] = {NULL};
	char	*tmp;

	if (fd < 0 || !line)
		return (-1);
	
	if ((rc = read(fd, buff, BUFF_SIZE)) != 0)
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
								printf("s[fd]:%s\n", s[fd]);

	if (ft_strlen(s[fd]) > 0)
		return (get_line(&s[fd], line));
	return (0);

	// if (rc != 0)
	// 	return (1);
	// return (0);
}

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<test purpose
int		main(int ac, char **av)
{
	int		fd;
	char	*line = NULL;
	
	if (ac == 1)
		fd = 0;
	else if (ac == 2)
		fd = open(av[1], O_RDONLY);
	else // invalid number of arguments
		return (-1);

	while (get_next_line(fd, &line))
		get_next_line(fd, &line);

	return (0);
}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>test purpose

// int		main(void)
// {
// 	int		fd;
// 	char	*line;

// 	if (fd = open("readme.txt", O_RDONLY) == - 1)
// 	{
// 		printf("file read error\n");
// 		return (1);
// 	}

// 	get_next_line(fd, &line);
// 	printf("line:%s\n", line);
// 	get_next_line(fd, &line);
// 	printf("line:%s\n", line);
// 	get_next_line(fd, &line);
// 	printf("line:%s\n", line);


// 	return (0);
// }
