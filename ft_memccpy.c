/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:56:10 by ademenet          #+#    #+#             */
/*   Updated: 2015/12/01 09:42:48 by ademenet         ###   ########.fr       */
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
	while (n--)
	{
		*pdst = *psrc;
		if (*psrc == (unsigned char)c)
			return (pdst++);
		pdst++;
		psrc++;
	}
	return (NULL);
}
