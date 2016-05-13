/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:44:32 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/12 14:00:31 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void		ft_putwstr(wchar_t *ws)
{
	size_t	len;

	len = ft_wstrlen(ws);
	while (len > 0)
	{
		ft_putwchar(*ws, f);
		ws++;
		len--;
	}
}
