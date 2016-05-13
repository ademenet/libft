/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 11:20:08 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/13 14:33:53 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/*
** This function takes a wchar_t and writes it. It starts with big endian
** and move to lower endians thanks to masks and bit operations.
** These are unicode masks:
** 0xxxxxxx // 0x00
** 110xxxxx 10xxxxxx // 0xC0 0x80
** 1110xxxx 10xxxxxx 10xxxxxx // 0xE0 0x80 0x80
** 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx // 0xF0 0x80 0x80 0x80
*/

void		ft_putwchar(wchar_t wchar, t_flag *f)
{
	int		size;

	size = ft_wcharlen(wchar);
	if (size == 1)
		ft_buf(wchar, f);
	else if (size == 2)
	{
		ft_buf((wchar >> 6) + 0xC0, f);
		ft_buf((wchar & 0x3F) + 0x80, f);
	}
	else if (size == 3)
	{
		ft_buf((wchar >> 12) + 0xE0, f);
		ft_buf(((wchar >> 6) & 0x3F) + 0x80, f);
		ft_buf((wchar & 0x3F) + 0x80, f);
	}
	else
	{
		ft_buf((wchar >> 18) + 0xF0, f);
		ft_buf(((wchar >> 12) & 0x3F) + 0x80, f);
		ft_buf(((wchar >> 6) & 0x3F) + 0x80, f);
		ft_buf((wchar & 0x3F) + 0x80, f);
	}
}
