/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 16:58:30 by eesaki            #+#    #+#             */
/*   Updated: 2019/04/30 18:45:22 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t len)
{
	char	*s2;
	size_t	n;

	n = (ft_strlen(s1) < len) ? ft_strlen(s1) : len;
	if (!(s2 = (char *)ft_memalloc(sizeof(char) * n + 1)))
		return (NULL);
	ft_strncpy(s2, s1, n);
	return (s2);
}
