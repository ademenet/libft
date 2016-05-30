/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_display_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 15:41:52 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/24 10:46:00 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fpf_printf.h"

void		fpf_display_arg(t_flag *f)
{
	int		i;
	size_t	len;

	if ((i = -1) && ((f->spe == 's' && f->fla[10] == 1) || f->spe == 'S' ||
		(f->spe == 'c' && f->fla[10] == 1) || f->spe == 'C'))
	{
		if (f->arg != NULL)
		{
			if (f->arg[0] == '\0' && (f->spe == 'C' ||
				(f->spe == 'c' && f->fla[10] == 1)))
				fpf_buf('\0', f);
			len = fpf_strlen(f->arg);
			while (len-- > 0)
				fpf_buf(f->arg[++i], f);
		}
		else if (f->fla[0] != -1)
			fpf_buf_null(f);
	}
	else
	{
		while (f->arg[++i] != '\0')
			fpf_buf(f->arg[i], f);
	}
	fpf_end(f);
}

int			fpf_width_rest(t_flag *f)
{
	return (f->fla[1] - fpf_strlen(f->arg));
}

/*
** Put 0 and space if width is bigger
*/

void		fpf_zero_char(t_flag *f)
{
	int		nb_space;

	nb_space = fpf_width_rest(f);
	if ((f->spe == 'c' && f->arg[0] == 0) || (f->spe == 'C' && f->arg[0] == 0))
		nb_space--;
	while (nb_space-- > 0)
	{
		if (f->fla[3] == 1 && f->fla[0] <= 0)
			fpf_buf('0', f);
		else
			fpf_buf(' ', f);
	}
	fpf_display_arg(f);
}

/*
** Put string on the right, add 0 and space if width is bigger
*/

void		fpf_minus_char(t_flag *f)
{
	int		nb_space;

	nb_space = fpf_width_rest(f);
	if ((f->spe == 'c' && f->arg[0] == 0) || (f->spe == 'C' && f->arg[0] == 0))
		nb_space--;
	fpf_display_arg(f);
	while (nb_space-- > 0)
		fpf_buf(' ', f);
}

/*
** Prends en compte la width
*/

void		fpf_width_char(t_flag *f)
{
	int		i;

	i = 0;
	if (f->arg)
		i = fpf_strlen(f->arg);
	if (i < f->fla[1])
	{
		if (f->fla[4] == 1)
			fpf_minus_char(f);
		else
			fpf_zero_char(f);
	}
	else
		fpf_display_arg(f);
}
