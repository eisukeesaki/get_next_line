/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 17:24:11 by eesaki            #+#    #+#             */
/*   Updated: 2019/04/12 13:48:37 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned long long	n;
	unsigned			neg;
	unsigned long long	max;

	n = 0;
	neg = 0;
	max = 9223372036854775807;
	while (ft_iswhitespace(*str))
		str++;
	neg = (*str == '-');
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		n = (n * 10) + (*str - '0');
		str++;
	}
	if ((neg == 0 && n > max) || (neg == 1 && n > max + 1))
		return (neg ? 0 : -1);
	return (neg ? -n : n);
}
