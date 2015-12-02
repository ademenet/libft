/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:13:28 by ademenet          #+#    #+#             */
/*   Updated: 2015/12/02 19:13:28 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	const size_t	dstlen = ft_strlen(dst);
	const size_t	srclen = ft_strlen(src);
	int	i;
	int j;
	size_t	n;

	i = 0;
	j = 0;
	n = size;
	if (size < dstlen)
		return (size + srclen);
	while (dst[i] != '\0' && i < (int)size)
		i++;
	while (n-- && i < (int)size)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	if (size == dstlen)
		return (dstlen);
	return (dstlen + size - n);
}
