/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 15:51:26 by ademenet          #+#    #+#             */
/*   Updated: 2016/06/28 15:54:05 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstappend(t_list *list, t_list *new)
{
	t_list		*cur;

	if (list && new)
	{
		cur = list;
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = new;
		new->next = NULL;
	}
}
