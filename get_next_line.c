/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 15:17:05 by eesaki            #+#    #+#             */
/*   Updated: 2019/04/26 18:35:52 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<test purpose
#include <stdio.h>
#include <fcntl.h>
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>test purpose

int		get_next_line(const int fd, char **line)
{

}

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<test purpose
int		main(void)
{
	int		fd;
	char	*line;

	if (fd = open("readme.txt", O_RDONLY) == - 1)
	{
		printf("file read error\n");
		return (1);
	}

	get_next_line(fd, &line);
	printf("line:%s\n", line);
	get_next_line(fd, &line);
	printf("line:%s\n", line);
	get_next_line(fd, &line);
	printf("line:%s\n", line);


	return (0);
}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>test purpose
