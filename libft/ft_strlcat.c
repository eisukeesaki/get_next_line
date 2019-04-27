/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 13:35:09 by eesaki            #+#    #+#             */
/*   Updated: 2019/04/12 13:35:09 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t k;

	i = 0;
	k = 0;
	while (dst[i] && i < dstsize)
		i++;
	if (i == dstsize)
		return (dstsize + ft_strlen(src));
	while (src[k] && (i + k + 1) < dstsize)
	{
		dst[i + k] = src[k];
		k++;
	}
	dst[i + k] = '\0';
	return (i + ft_strlen(src));
}
