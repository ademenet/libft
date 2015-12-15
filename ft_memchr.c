/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:35:28 by ademenet          #+#    #+#             */
/*   Updated: 2015/12/14 18:13:21 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	/*	unsigned char	*ps;

		if (s)
		{
		ps = (unsigned char *)s;
		while (n--)
		{
		if (*ps == (unsigned char)c)
		return ((void *)ps);
		ps++;
		}
		}
		return (NULL);*/

	size_t				p;
	unsigned char		*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	p = 0;
	while (p < n)
	{
		d[p] = s[p];
		if (d[p] == (unsigned char)c)
			return (dest + p + 1);
		p++;
	}
	return (NULL);
}
