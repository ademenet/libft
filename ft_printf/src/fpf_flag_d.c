/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_flag_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 18:20:57 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/24 10:46:22 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fpf_printf.h"

char	*fpf_modifier_d(t_flag *f, va_list *ap)
{
	intmax_t	data;
	uintmax_t	data_max;

	data = 0;
	if (f->fla[12] == 1)
		data = (intmax_t)(va_arg(*ap, ssize_t));
	else if (f->fla[11] == 1)
		data = (va_arg(*ap, intmax_t));
	else if (f->fla[9] == 1)
		data = (intmax_t)(va_arg(*ap, long long));
	else if (f->fla[10] == 1)
		data = (intmax_t)(va_arg(*ap, long));
	else if (f->fla[8] == 1)
		data = (intmax_t)((short)va_arg(*ap, int));
	else if (f->fla[7] == 1)
		data = (intmax_t)((char)va_arg(*ap, int));
	else if (f->spe == 'D')
		data = (intmax_t)(va_arg(*ap, long));
	else if (f->spe == 'd' || f->spe == 'i')
		data = (intmax_t)(va_arg(*ap, int));
	data_max = fpf_sign(f, data);
	return (fpf_itoa_base(data_max, 10));
}

int		fpf_handler_d(t_flag *f, va_list *ap)
{
	static int	mask_d[13] = {0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

	fpf_apply_mask(f, mask_d);
	f->arg = fpf_modifier_d(f, ap);
	fpf_handler_numb(f);
	return (0);
}

int		fpf_handler_wd(t_flag *f, va_list *ap)
{
	static int	mask_wd[13] = {0, 0, 2, 1, 1, 1, 1, 2, 2, 1, 2, 1, 1};

	fpf_apply_mask(f, mask_wd);
	f->arg = fpf_modifier_d(f, ap);
	fpf_handler_numb(f);
	return (0);
}
