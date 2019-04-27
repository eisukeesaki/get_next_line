/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 19:35:49 by eesaki            #+#    #+#             */
/*   Updated: 2019/03/26 18:59:36 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	long		nb;
	size_t		dgt;
	char		*s;
	unsigned	neg;

	nb = n;
	neg = n < 0 ? 1 : 0;
	dgt = ft_count_digit(nb);
	s = ft_strnew(dgt + neg);
	if (!s)
		return (NULL);
	if (neg)
	{
		nb = -nb;
		s[0] = '-';
	}
	while (dgt > 0)
	{
		s[dgt + neg - 1] = (nb % 10) + '0';
		dgt--;
		nb /= 10;
	}
	return (s);
}
