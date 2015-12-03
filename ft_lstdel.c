/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 17:31:18 by ademenet          #+#    #+#             */
/*   Updated: 2015/12/03 17:55:11 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	while (**alst->next)
	{
		(*del)(**alst->content, **alst->content_size);
		**alst->next = NULL;
		free(*alst);
	}
}
