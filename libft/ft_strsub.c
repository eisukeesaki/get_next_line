/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 15:25:51 by eesaki            #+#    #+#             */
/*   Updated: 2019/03/25 16:03:59 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned	i;
	char		*new;

	i = 0;
	new = ft_strnew(len);
	if (!s)
		return (NULL);
	if (!new)
		return (NULL);
	while (i < len)
	{
		new[i] = s[i + start];
		i++;
	}
	return (new);
}
