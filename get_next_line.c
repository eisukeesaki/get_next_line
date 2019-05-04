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
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<test purpose
#include <stdio.h>
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>test purpose

int		get_line(char **str, char **line)
{
	char	*nl;
	char	*tmp;

	while ((nl = ft_strchr(*str, '\n')))
	{
		*line = ft_strndup(*str, (nl - *str));
		tmp = ft_strdup(nl + 1);
		free(*str);
		*str = tmp;
		return (1);
	}
	if (str)
	{
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
	char		*tmp;
	int			rc;

	if (fd < 0 || !line || BUFF_SIZE <= 0 || read(fd, buff, 0) < 0)
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

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<42FC
int		main(void)
{
	char	*line = NULL;
	int		fd1;
	// int		fd2;

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<fd1
	if ((fd1 = open("./input1.txt", O_RDONLY)) == 1)
		puts("file open error");
	printf("fd1:%d\n", fd1);
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>fd1

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<fd2
	// if ((fd2 = open("./input2.txt", O_RDONLY)) == 1)
		// puts("file open error");
	// printf("fd2:%d\n", fd2);
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>fd2

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<fd1
	while (get_next_line(fd1, &line))
	{
		ft_putstr(line);
		ft_strdel(&line);
	}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>fd1
	
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<fd2
	// while (get_next_line(fd2, &line))
	// {
	// 	ft_putstr(line);
	// 	ft_strdel(&line);
	// }
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>fd2

	close(fd1);
	// close(fd2);
	
	// while (1);
	return (0);
}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>42FC

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
// 	// while (1);
// 	return (0);
// }
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>test purpose

// // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<fc10
// void caller()
// {
// 		char		*line = NULL;
// 	int			fd1 = open("./gnl10.txt", O_RDONLY);
// 	//int 		fd2 = open("./input.txt", O_RDONLY);			

// 	get_next_line(fd1, &line);
// 	get_next_line(fd2, &line);
// 	close(fd1);
// 	close(fd2);
// 	ft_strdel(&line);
// }

// int				main(void)
// {
// 	caller();
// 	// sleep(15);
// 	while (1);
// 	return (0);
// }
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>fc10

	// if (*str)
	// {
	// 	if (!(nl = ft_strchr(*str, '\n'))) // no \n
	// 	{
	// 		*line = ft_strdup(*str);
	// 		*str[0] = '\0';
	// 		return (1);
	// 	}
	// 	if (nl != *str) // \n not at beginning
	// 	{
	// 		*line = ft_strndup(*str, (nl - *str));
	// 		*str = nl + 1;
	// 	}
	// 	else // \n at beginning
	// 	{
	// 		*line = ft_strnew(0);
	// 		// *line = NULL;
	// 		*str = nl + 1;
	// 		return (1);
	// 	}
	// }
	// // if (ft_strlen(*line) > 0)
	// 	return (1);