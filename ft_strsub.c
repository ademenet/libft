/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:16:23 by ademenet          #+#    #+#             */
/*   Updated: 2015/11/26 11:28:02 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fresh;
	int		i;

	fresh = malloc(len * sizeof(char));
	i = 0;
	if (!fresh)
		return (NULL);
	while (len--)
	{
		fresh[i] = s[start];
		i++;
		start++;
	}
	return (&fresh[0]);
}
