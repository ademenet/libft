/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_wstrlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 15:59:17 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/24 10:45:02 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fpf_printf.h"

size_t		fpf_wbytelen(wchar_t *ws)
{
	size_t	len;
	size_t	bytelen;

	len = fpf_wstrlen(ws);
	bytelen = 0;
	while (len > 0)
	{
		bytelen += fpf_wcharlen(*ws);
		ws++;
		len--;
	}
	return (bytelen);
}

size_t		fpf_wstrlen(wchar_t *ws)
{
	size_t	len;

	len = 0;
	if (!ws)
		return (0);
	while (*(ws++))
		len++;
	return (len);
}
