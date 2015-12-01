/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:44:06 by ademenet          #+#    #+#             */
/*   Updated: 2015/11/26 08:30:24 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	dst = malloc(len);
	while (s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	return (&dst[0]);
}
