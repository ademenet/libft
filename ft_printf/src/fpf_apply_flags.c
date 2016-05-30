/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_apply_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 15:23:29 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/24 10:45:33 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fpf_printf.h"

/*
** Pas de free dans la precision WARNING
** Sub string if 's' or 'S'.
*/

void	fpf_precision_string(t_flag *f)
{
	if (f->fla[0] == -1)
		f->arg = "\0";
	else if (f->spe == 'S' || (f->spe == 's' && f->fla[10] == 1))
		f->arg = fpf_wstrsub(f->warg, 0, f->fla[0]);
	else if (f->spe == 's')
		f->arg = fpf_strsub(f->arg, 0, f->fla[0]);
}

/*
** Ajout 0 pour o et O, 0x pour x et p, 0X pour X
*/

void	fpf_sharp(t_flag *f)
{
	if ((f->fla[2] == 1 && f->arg[0] != '0' && f->fla[0] != -1)
		|| f->spe == 'p')
	{
		if (f->spe == 'o' || f->spe == 'O' || f->spe == 'x' || f->spe == 'X' ||
			f->spe == 'p')
		{
			if ((f->spe == 'x' && f->arg[0] != '0') || f->spe == 'p')
			{
				fpf_buf('0', f);
				fpf_buf('x', f);
			}
			else if (f->spe == 'X' && f->arg[0] != '0')
			{
				fpf_buf('0', f);
				fpf_buf('X', f);
			}
			else if ((f->spe == 'o' || f->spe == 'O') &&
				f->fla[0] <= fpf_strlen(f->arg))
				fpf_buf('0', f);
			else if ((f->spe == 'o' || f->spe == 'O') && f->fla[0] == -1)
				fpf_buf('0', f);
		}
	}
}

/*
** Ajoute un espace si flag ' ' OU un signe +/- si flag '+'
** appelle la fonction fpf_sharp
*/

void	fpf_space_plus_sharp(t_flag *f)
{
	if (f->fla[5] == 1 || f->fla[6] == 1)
	{
		if (f->spe == 'd' || f->spe == 'D' || f->spe == 'i')
		{
			if (f->fla[6] == 1 && f->fla[5] == 0 && f->sign != '-')
				fpf_buf(' ', f);
			if (f->fla[5] == 1 && fpf_isdigit(f->arg[0]) && f->sign == '+')
				fpf_buf('+', f);
		}
	}
	if (f->sign == '-')
		fpf_buf('-', f);
	fpf_sharp(f);
}
