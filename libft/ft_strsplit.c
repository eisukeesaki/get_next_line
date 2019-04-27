/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 12:51:29 by eesaki            #+#    #+#             */
/*   Updated: 2019/04/12 16:21:21 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline size_t	wordlen(char const *s, char d)
{
	size_t l;

	l = 0;
	while (s[l] && s[l] != d)
		l++;
	return (l);
}

static inline char		*next_word(char const *s, char d)
{
	while (*s == d && *s)
		s++;
	return ((char *)s);
}

char					**ft_strsplit(char const *s, char c)
{
	char	**split;
	size_t	wc;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	wc = ft_words(s, c);
	if (!(split = (char **)ft_memalloc((wc + 1) * sizeof(char *))))
		return (NULL);
	while (i < wc)
	{
		s = next_word((char *)s, c);
		split[i] = ft_strsub(s, 0, wordlen(s, c));
		i++;
		s += wordlen(s, c);
	}
	split[wc] = NULL;
	return (split);
}
