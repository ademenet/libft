/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_wildcard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 16:41:44 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/24 10:47:27 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fpf_printf.h"

int			fpf_wildcard(t_flag *f, va_list *ap, int index)
{
	if (f->frmt[f->ndx] == '*')
	{
		f->fla[index] = va_arg(*ap, int);
		if (f->fla[index] < 0)
		{
			if (index == 1)
			{
				f->fla[4] = 1;
				f->fla[1] *= -1;
			}
			else if (index == 0)
			{
				f->fla[0] = 0;
				f->ndx++;
				return (0);
			}
		}
		f->ndx++;
	}
	return (1);
}
