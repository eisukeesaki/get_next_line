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

	while ((nl = ft_strchr(*str, '\n'))) // while there's a \n
	{
		*line = ft_strndup(*str, (nl - *str)); // dup first char to \n
		tmp = ft_strdup(nl + 1); // assing next starting pos to tmp
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

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<42FC
int		main(void)
{
	char	*line = NULL;
	int		fd1;
	int		fd2;

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<fd1
	if ((fd1 = open("./input1.txt", O_RDONLY)) == 1)
		puts("file open error");
	printf("fd1:%d\n", fd1);
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>fd1

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<fd2
	if ((fd2 = open("./input2.txt", O_RDONLY)) == 1)
		puts("file open error");
	printf("fd2:%d\n", fd2);
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>fd2

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<read alternalely
	get_next_line(fd1, &line);
	ft_putendl(line);
	ft_strdel(&line);

	get_next_line(fd2, &line);
	ft_putendl(line);
	ft_strdel(&line);

	get_next_line(fd1, &line);
	ft_putendl(line);
	ft_strdel(&line);

	get_next_line(fd2, &line);
	ft_putendl(line);
	ft_strdel(&line);
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>read alternalely

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<fd1
	// while (get_next_line(fd1, &line))
	// {
	// 	// ft_putstr(line);
	// 	ft_putendl(line);
	// 	ft_strdel(&line);
	// }
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>fd1
	
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<fd2
	// while (get_next_line(fd2, &line))
	// {
	// 	// ft_putstr(line);
	// 	ft_putendl(line);
	// 	ft_strdel(&line);
	// }
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>fd2

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<close files
	close(fd1);
	close(fd2);
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>close files

	// while (1); // keep process running
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