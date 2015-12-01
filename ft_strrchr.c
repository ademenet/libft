/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 09:32:53 by ademenet          #+#    #+#             */
/*   Updated: 2015/12/01 17:00:50 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*strr;

	strr = NULL;
	while (*s)
	{
		if (*s == (char)c)
			strr = (char *)s;
		s++;
	}
	if (*s == (char)c)
		strr = (char *)s;
	return (strr);
}
