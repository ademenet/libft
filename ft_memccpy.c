/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:56:10 by ademenet          #+#    #+#             */
/*   Updated: 2015/12/02 17:01:06 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char			*pdst;
	unsigned char			*psrc;

	pdst = (unsigned char *)dst;
	psrc = (unsigned char *)src;
	while (n-- && *psrc != (unsigned char)c)
	{
		*pdst = *psrc;
		pdst++;
		psrc++;
	}
	if (*psrc == (unsigned char)c)
		return ((void *)(pdst + 1));
	return (NULL);
}
