/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:33:36 by ademenet          #+#    #+#             */
/*   Updated: 2015/12/01 16:48:53 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*text;
	char	*fresh;
	size_t	len;
	int		i;

	i = 0;
	text = ft_strcat((char *)s1, s2);
	len = ft_strlen(text);
	fresh = (char *)malloc(len * sizeof(char));
	while (text[i] != '\0')
	{
		fresh[i] = text[i];
		i++;
	}
	return (&fresh[0]);
}
