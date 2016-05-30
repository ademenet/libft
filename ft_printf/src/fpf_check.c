/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 12:24:50 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/24 10:45:47 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fpf_printf.h"

/*
** This function reads each flags and call functions in order to save them.
** First, initialize our int array.
*/

int			fpf_check(t_flag *f, va_list *ap)
{
	fpf_check_initialize(f);
	while (f->frmt[f->ndx] == '#' || f->frmt[f->ndx] == '0'
		|| f->frmt[f->ndx] == '-' || f->frmt[f->ndx] == '+'
		|| f->frmt[f->ndx] == ' ' || f->frmt[f->ndx] == 'h'
		|| f->frmt[f->ndx] == 'l' || f->frmt[f->ndx] == 'j'
		|| f->frmt[f->ndx] == 'z' || f->frmt[f->ndx] == '.'
		|| f->frmt[f->ndx] == '*' || fpf_isdigit(f->frmt[f->ndx]))
	{
		fpf_check_flag(f);
		fpf_check_width(f, ap);
		fpf_check_precision(f, ap);
		fpf_check_modifier(f);
	}
	if (f->ndx == fpf_strlen(f->frmt))
		return (-1);
	return (0);
}

/*
** This function compare the current char with flags and put an int through the
** mask.
*/

void		fpf_check_flag(t_flag *f)
{
	if (f->frmt[f->ndx] == '#' || f->frmt[f->ndx] == '0'
		|| f->frmt[f->ndx] == '-' || f->frmt[f->ndx] == '+'
		|| f->frmt[f->ndx] == ' ')
	{
		if (f->frmt[f->ndx] == '#')
			f->fla[2] = 1;
		if (f->frmt[f->ndx] == '0')
			f->fla[3] = 1;
		if (f->frmt[f->ndx] == '-')
			f->fla[4] = 1;
		if (f->frmt[f->ndx] == '+')
			f->fla[5] = 1;
		if (f->frmt[f->ndx] == ' ')
			f->fla[6] = 1;
		f->ndx++;
	}
}

/*
** This function check the witdh if we find a digit.
*/

void		fpf_check_width(t_flag *f, va_list *ap)
{
	int		i;
	char	*str;

	i = f->ndx;
	if (fpf_isdigit(f->frmt[f->ndx]) && f->frmt[f->ndx] != '0')
	{
		while (fpf_isdigit(f->frmt[f->ndx]))
			f->ndx++;
		if (f->ndx - i > 0)
		{
			f->fla[1] = 0;
			str = fpf_strsub(f->frmt, i, f->ndx - i);
			f->fla[1] = fpf_atoi((const char*)str);
			free(str);
		}
	}
	fpf_wildcard(f, ap, 1);
}

/*
** This function check the precision if we find a dot.
*/

void		fpf_check_precision(t_flag *f, va_list *ap)
{
	int		i;
	int		flag;
	char	*str;

	if (f->frmt[f->ndx] == '.')
	{
		f->fla[0] = 0;
		i = ++f->ndx;
		if (f->frmt[f->ndx] == '*')
			flag = fpf_wildcard(f, ap, 0);
		else
		{
			while (fpf_isdigit(f->frmt[f->ndx]))
				f->ndx++;
			if (f->ndx - i > 0)
			{
				str = fpf_strsub(f->frmt, i, f->ndx - i);
				f->fla[0] = fpf_atoi((const char*)str);
				free(str);
			}
		}
		if (f->fla[0] == 0 && flag)
			f->fla[0] = -1;
	}
}

/*
** This function compare and analyse the modifiers.
*/

void		fpf_check_modifier(t_flag *f)
{
	while (f->frmt[f->ndx] == 'h' || f->frmt[f->ndx] == 'l' ||
		f->frmt[f->ndx] == 'j' || f->frmt[f->ndx] == 'z')
	{
		if (f->frmt[f->ndx] == 'h' && f->frmt[f->ndx + 1] == 'h')
		{
			f->fla[7] = 1;
			f->ndx++;
		}
		else if (f->frmt[f->ndx] == 'h')
			f->fla[8] = 1;
		if (f->frmt[f->ndx] == 'l' && f->frmt[f->ndx + 1] == 'l')
		{
			f->fla[9] = 1;
			f->ndx++;
		}
		else if (f->frmt[f->ndx] == 'l')
			f->fla[10] = 1;
		if (f->frmt[f->ndx] == 'j')
			f->fla[11] = 1;
		if (f->frmt[f->ndx] == 'z')
			f->fla[12] = 1;
		f->ndx++;
	}
}
