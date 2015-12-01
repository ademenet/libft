/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:35:28 by ademenet          #+#    #+#             */
/*   Updated: 2015/11/29 18:18:09 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ps;

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
	return (NULL);
}
