/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 15:17:05 by eesaki            #+#    #+#             */
/*   Updated: 2019/05/02 20:01:48 by eesaki           ###   ########.fr       */
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
		if (!(nl = ft_strchr(*str, '\n'))) // no \n
		{
			*line = ft_strdup(*str);
			*str[0] = '\0';
			return (1);
		}
		if (nl != *str) // \n not at beginning
		{
			*line = ft_strndup(*str, (nl - *str));
			*str = nl + 1;
		}
		else // \n at beginning
		{
			*line = ft_strnew(0);
			// *line = NULL;
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
// 	{
// 		ft_putendl(line);
// 		ft_strdel(&line);
// 	}
// 	close(fd);
// 	while (1);
// 	return (0);
// }
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>test purpose

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<42FC
int				main(void)
{
	char		*line = NULL;
	int			fd;

	fd = open("./input.txt", O_RDONLY);
	printf("fd:%d\n", fd);
	get_next_line(fd, &line);
	printf("line:%s\n", line);
	close(fd);
	free(line);
	// while (1);

	fd = open("./input2.txt", O_RDONLY);
	if (fd == -1)
		puts("file open error");
	printf("fd:%d\n", fd);
	get_next_line(fd, &line);
	printf("line:%s\n", line);
	close(fd);
	free(line);

	// fd = open("./input3.txt", O_RDONLY);
	// printf("fd:%d\n", fd);
	// get_next_line(fd, &line);
	// printf("line:%s\n", line);
	// close(fd);

	return (0);
}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>42FC