/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:05:26 by ademenet          #+#    #+#             */
/*   Updated: 2015/11/30 18:40:12 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static int		ft_sizeofanint(int n)
{
	int		size;

	size = 0;
	if (n < 0)
		size++;
	if (n > 9)
	{
		n = n / 10;
		size++;
	}
	return (size++);
}

char	*ft_itoa(int n)
{
	int		length;
	char	*fresh;

	length = ft_sizeofanint(n);
	fresh = (char *)malloc((length + 1) * sizeof(char));
	fresh[length] = '\0';
	length--;
	while (length >= 0)
	{
		fresh[length] = n + 48;
		length--;
	}
	if (n < 0)
	{
		fresh[0] = '-';
	}
	return (fresh);
}
