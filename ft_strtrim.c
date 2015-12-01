/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:44:03 by ademenet          #+#    #+#             */
/*   Updated: 2015/12/01 16:51:02 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*fresh;
	int		start;
	int		end;
	int		len;
	int		i;

	start = 0;
	end = ft_strlen(s);
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	if (start == 0 || end == 0)
		return ((char *)s);
	len = (int)ft_strlen(s) - (start + end);
	fresh = (char *)malloc(len * sizeof(char));
	if (!fresh)
		return (NULL);
	i = 0;
	while (start != end)
	{
		fresh[i] = s[start];
		start++;
	}
	return (fresh);
}
