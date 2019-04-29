/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 15:16:33 by eesaki            #+#    #+#             */
/*   Updated: 2019/04/28 17:59:47 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFF_SIZE 3
#define FD_MAX 1024

#include "libft/libft.h"
#include <unistd.h>
#include <fcntl.h>

int		get_next_line(const int fd, char **line);
