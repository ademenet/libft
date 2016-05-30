/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 18:49:48 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/24 10:47:05 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fpf_printf.h"

void		fpf_apply_mask(t_flag *f, int *mask)
{
	int		i;

	i = 2;
	while (i < 14)
	{
		f->fla[i] = f->fla[i] * mask[i];
		i++;
	}
}

int			fpf_handler_char(t_flag *f)
{
	if (f->fla[0] != 0 && (f->spe != 'C' || (f->spe == 'c' && f->fla[10] == 1)))
		fpf_precision_string(f);
	else if (f->spe == 'S' || (f->spe == 's' && f->fla[10] == 1) ||
		f->spe == 'C' || (f->spe == 'c' && f->fla[10] == 1))
		f->arg = fpf_transform_wchar_in_char(f->warg);
	if (f->fla[1] > 0)
		fpf_width_char(f);
	if (f->fla[1] == 0)
		fpf_display_arg(f);
	return (1);
}

int			fpf_handler_numb(t_flag *f)
{
	int	i;

	i = -1;
	if (f->fla[0] == -1 && f->arg[0] == '0' && !(f->fla[2] == 1 &&
		(f->spe == 'o' || f->spe == 'O' || f->spe == 'p')))
		f->arg = "\0";
	if (f->fla[1] > 0)
		fpf_width_numb(f);
	else if (f->fla[1] == 0 && f->fla[0] > 0)
		fpf_precision_without_width(f);
	if (f->fla[0] <= 0 && f->fla[1] == 0)
		fpf_space_plus_sharp(f);
	while (f->arg[++i] != '\0' && f->fla[1] == 0)
		fpf_buf(f->arg[i], f);
	fpf_end(f);
	return (1);
}
