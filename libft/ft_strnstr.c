/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 12:56:19 by eesaki            #+#    #+#             */
/*   Updated: 2019/04/12 15:54:57 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strnstr(const char *haystack, const char *needle,
																size_t len)
{
	size_t	h;
	size_t	n;
	size_t	nlen;

	if (*needle == '\0')
		return ((char *)haystack);
	nlen = ft_strlen(needle);
	h = 0;
	n = 0;
	while (haystack[h] && len >= nlen)
	{
		if (haystack[h] == needle[n] &&
			ft_strncmp(&haystack[h], &needle[n], nlen) == 0)
			return ((char *)&haystack[h]);
		len--;
		h++;
	}
	return (NULL);
}
