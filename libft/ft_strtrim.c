/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 19:13:19 by eesaki            #+#    #+#             */
/*   Updated: 2019/03/27 13:14:15 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		head;
	int		tail;
	char	*str;

	if (!s)
		return (NULL);
	head = 0;
	tail = ft_strlen(s);
	while (ft_iswhitespace(s[head]))
		head++;
	while (ft_iswhitespace(s[tail - 1]))
		tail--;
	if (tail < head)
		tail = head;
	str = ft_strnew(tail - head);
	if (!str)
		return (NULL);
	return (ft_strncpy(str, s + head, tail - head));
}
