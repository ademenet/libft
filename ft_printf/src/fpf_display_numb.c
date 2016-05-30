/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_display_numb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 15:41:52 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/24 10:46:07 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fpf_printf.h"

/*
** Appelle la fonction space_plus_sharp, width == 0 et precision > 0
** ajout des 0 pour completer la precision
*/

void	fpf_precision_without_width(t_flag *f)
{
	int	len;
	int	prec;

	prec = f->fla[0];
	len = fpf_strlen(f->arg);
	fpf_space_plus_sharp(f);
	while (prec > len-- && len > 0)
		prec--;
	if (f->fla[0] > f->fla[1] + fpf_strlen(f->arg))
	{
		while (++len < prec)
			fpf_buf('0', f);
	}
}

/*
** Remove more space on width for '-' flag
** Gere l'affichage si '-' apres avoir affiche les arguments + flags :
** longueur des ' ' a afficher et affiche
*/

void	fpf_precision_numb(t_flag *f, int len_zero)
{
	int	len;

	len = fpf_strlen(f->arg);
	if (f->fla[5] == 1 || f->fla[6] == 1 || f->sign == '-' || (f->fla[2] == 1 &&
		f->fla[0] <= len && (f->spe == 'o' || f->spe == 'O')))
		len_zero--;
	if (f->fla[2] == 1 && (f->spe == 'x' || f->spe == 'X' || f->spe == 'p'))
		len_zero = len_zero - 2;
	while (f->fla[0] > len++)
		len_zero--;
	if (f->fla[0] < f->fla[1] + fpf_strlen(f->arg))
	{
		while (len_zero-- > 0)
		{
			if (f->fla[3] == 1 && f->fla[0] == 0)
				fpf_buf('0', f);
			else
				fpf_buf(' ', f);
		}
	}
}

/*
** Put 0 and space if width is bigger
*/

void	fpf_zero_numb(t_flag *f)
{
	int		i;
	int		len;
	int		len_zero;

	i = -1;
	len = fpf_strlen(f->arg);
	len_zero = f->fla[1] - len;
	if (f->fla[3] == 1)
	{
		fpf_space_plus_sharp(f);
		fpf_precision_numb(f, len_zero);
	}
	else
	{
		fpf_precision_numb(f, len_zero);
		fpf_space_plus_sharp(f);
	}
	while (f->fla[0] > len++)
		fpf_buf('0', f);
	while (f->arg[++i] != '\0')
		fpf_buf(f->arg[i], f);
}

/*
** Put string on the right, add 0 and space if width is bigger
*/

void	fpf_minus_numb(t_flag *f)
{
	int		i;
	int		len;
	int		len_zero;

	i = -1;
	len_zero = f->fla[1] - fpf_strlen(f->arg);
	len = fpf_strlen(f->arg);
	f->fla[3] = 0;
	fpf_space_plus_sharp(f);
	while (f->fla[0] > len++)
		fpf_buf('0', f);
	while (f->arg[++i] != '\0')
		fpf_buf(f->arg[i], f);
	fpf_precision_numb(f, len_zero);
}

/*
** Prends en compte la width
*/

void	fpf_width_numb(t_flag *f)
{
	int	i;
	int	len;

	i = -1;
	len = fpf_strlen(f->arg);
	if (len < f->fla[1])
	{
		if (f->fla[4] == 1)
			fpf_minus_numb(f);
		else
			fpf_zero_numb(f);
	}
	else
	{
		fpf_space_plus_sharp(f);
		while (f->fla[0] > len++)
			fpf_buf('0', f);
		while (f->arg[++i] != '\0')
			fpf_buf(f->arg[i], f);
	}
}
