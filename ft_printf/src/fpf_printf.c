/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 14:18:27 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/24 11:00:44 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fpf_printf.h"

/*
** This our main function, it tooks our string and arguments, displays them or
** call subsidiaries functions to manage flags.
*/

void		fpf_end(t_flag *f)
{
	if (f->fla[0] >= 0 && f->arg != NULL && f->arg[0] != '\0' &&
		f->arg[0] != '0')
	{
		if (f->spe == 'x' || f->spe == 'X' || f->spe == 'o' || f->spe == 'O'
			|| f->spe == 'u' || f->spe == 'U' || f->spe == 'd' || f->spe == 'D'
			|| f->spe == 'p' || f->spe == 'S' || f->spe == 'i' || (f->spe == 's'
			&& f->fla[0] < fpf_strlen(f->arg) && f->fla[0] > 0) || f->spe == 'C'
			|| (f->spe == 'c' && f->fla[10] == 1))
			free(f->arg);
	}
}

void		fpf_start(const char *format, t_flag *f, va_list *ap)
{
	int		i;

	i = -1;
	while (format[++i] != '\0')
	{
		if (format[i] == '%')
		{
			f->frmt = (char*)&format[++i];
			if (fpf_dispatcher(f, ap) == -1)
				break ;
			i += f->ndx;
		}
		else if (format[i] != '\0' && format[i] != '%')
			fpf_buf(format[i], f);
	}
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	t_flag	f;

	va_start(ap, format);
	f.ret = 0;
	fpf_bufset();
	if (!format)
		return (0);
	fpf_start(format, &f, &ap);
	if (g_i > 0)
		fpf_display(&f);
	va_end(ap);
	return (f.ret);
}
