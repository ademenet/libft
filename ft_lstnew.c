/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 12:22:40 by ademenet          #+#    #+#             */
/*   Updated: 2015/12/03 18:34:23 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_link;

	new_link = (t_list *)malloc(content_size);
	if (!new_link)
		return (NULL);
	if (content == NULL)
	{
		new_link->content = NULL;
		new_link->content_size = (size_t)0;
	}
	else
	{
		ft_memcpy(new_link->content, content, content_size);
		new_link->content_size = content_size;
		new_link->next = NULL;
	}
	return(new_link);
}
