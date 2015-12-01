/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:31:08 by ademenet          #+#    #+#             */
/*   Updated: 2015/11/25 18:27:36 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char	*pdst;

	pdst = dst;
	while (*src != '\0' && n > 0)
	{
		*pdst++ = *src++;
		n--;
	}
	while (n > 0)
	{
		*pdst++ = '\0';
		n--;
	}
	return (dst);
}
