/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 08:48:08 by ademenet          #+#    #+#             */
/*   Updated: 2015/12/15 16:00:50 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*text;

	text = (char *)malloc((size + 1) * sizeof(char));
	if (!text)
		return (NULL);
	ft_bzero(text, size);
	text[size] = '\0';
	return (text);
}
