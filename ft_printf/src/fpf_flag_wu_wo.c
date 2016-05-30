/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_flag_wu_wo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 12:45:04 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/24 10:46:53 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fpf_printf.h"

char		*fpf_modifier_wu_wo(t_flag *f, va_list *ap)
{
	intmax_t	data;

	if (f->fla[12] == 1)
		data = (uintmax_t)va_arg(*ap, size_t);
	else if (f->fla[11] == 1)
		data = va_arg(*ap, uintmax_t);
	else if (f->fla[9] == 1)
		data = (uintmax_t)va_arg(*ap, unsigned long long);
	else if (f->fla[10] == 1)
		data = (uintmax_t)va_arg(*ap, unsigned long);
	else if (f->fla[8] == 1)
		data = (uintmax_t)va_arg(*ap, unsigned int);
	else if (f->fla[7] == 1)
		data = (uintmax_t)va_arg(*ap, unsigned int);
	else
		data = (uintmax_t)va_arg(*ap, unsigned long);
	if (f->spe == 'U')
		return (fpf_itoa_base(data, 10));
	if (f->spe == 'O')
		return (fpf_itoa_base(data, 8));
	return (NULL);
}

int			fpf_handler_wu(t_flag *f, va_list *ap)
{
	static int	mask_wu[13] = {0, 0, 2, 1, 1, 1, 1, 2, 2, 1, 2, 1, 1};

	fpf_apply_mask(f, mask_wu);
	f->arg = fpf_modifier_wu_wo(f, ap);
	fpf_handler_numb(f);
	return (0);
}

int			fpf_handler_wo(t_flag *f, va_list *ap)
{
	static int	mask_wo[13] = {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

	fpf_apply_mask(f, mask_wo);
	f->arg = fpf_modifier_wu_wo(f, ap);
	if (f->fla[0] == -1 && f->arg[0] != '0' && f->fla[2] == 1)
		f->fla[0] = 0;
	fpf_handler_numb(f);
	return (0);
}
