/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_printf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 14:27:23 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/30 17:11:16 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FPF_PRINTF_H
# define FPF_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>

char			g_buf[4096];
int				g_i;

/*
** fla[13] is an array which contains flags for precision, width, flags
** and modifiers such as:
** |0        |1    |2|3|4|5|6|7 |8|9 |10|11|12|
** |precision|width|#|0|-|+| |hh|h|ll|l |j |z |
*/

typedef struct	s_flag
{
	int			ret;
	char		*frmt;
	int			ndx;
	char		spe;
	char		*arg;
	wchar_t		*warg;
	char		sign;
	va_list		ap;
	int			fla[13];
}				t_flag;

typedef struct	s_spec
{
	char		c;
	int			(*ptr)();
}				t_spec;

/*
** fpf_PRINTF
*/

void			fpf_end(t_flag *f);
void			fpf_start(const char *format, t_flag *f, va_list *ap);
int				ft_printf(const char *format, ...);

/*
** CHECKS
*/

int				fpf_check(t_flag *f, va_list *ap);
void			fpf_check_initialize(t_flag *f);
void			fpf_check_flag(t_flag *f);
void			fpf_check_width(t_flag *f, va_list *ap);
void			fpf_check_precision(t_flag *f, va_list *ap);
void			fpf_check_modifier(t_flag *f);

/*
** UTILS
*/

int				fpf_isdigit(int c);
char			*fpf_strsub(char const *s, unsigned int start, size_t len);
char			*fpf_itoa_base(uintmax_t nbr, int base);
uintmax_t		fpf_sign(t_flag *f, intmax_t nbr);
int				fpf_strlen(char *str);
long			fpf_atoi(const char *str);
char			*fpf_strlwr(char *s1);

/*
** Les Wchars
*/

void			fpf_putwchar(wchar_t wchar, t_flag *f);
int				fpf_wcharlen(wchar_t wchar);
size_t			fpf_wbytelen(wchar_t *ws);
size_t			fpf_wstrlen(wchar_t *ws);
char			*fpf_wstrsub(wchar_t *ws, unsigned int start, size_t len);
char			*fpf_strsub_with_free(char const *s, unsigned int start,
				size_t len);
char			*fpf_transform_wchar_in_char(wchar_t *ws);
int				fpf_putwchar_in_char(wchar_t wchar, char *fresh, int i);

/*
** DISPATCHER
*/

void			fpf_initialize_specs(t_spec *specs);
int				fpf_dispatcher(t_flag *f, va_list *ap);

/*
** HANDLERS: functions that handle specifiers
*/

void			fpf_apply_mask(t_flag *f, int *mask);

int				fpf_handler_char(t_flag *f);
int				fpf_handler_numb(t_flag *f);

int				fpf_handler_c(t_flag *f, va_list *ap);
int				fpf_handler_wc(t_flag *f, va_list *ap);
int				fpf_modifier_wc(t_flag *f, va_list *ap);

int				fpf_handler_s(t_flag *f, va_list *ap);
int				fpf_handler_ws(t_flag *f, va_list *ap);

int				fpf_handler_d(t_flag *f, va_list *ap);
int				fpf_handler_wd(t_flag *f, va_list *ap);
char			*fpf_modifier_d(t_flag *f, va_list *ap);

int				fpf_handler_o(t_flag *f, va_list *ap);
int				fpf_handler_u(t_flag *f, va_list *ap);
int				fpf_handler_b(t_flag *f, va_list *ap);
char			*fpf_modifier_u_o(t_flag *f, va_list *ap);

int				fpf_handler_wo(t_flag *f, va_list *ap);
int				fpf_handler_wu(t_flag *f, va_list *ap);
char			*fpf_modifier_wu_wo(t_flag *f, va_list *ap);

int				fpf_handler_x(t_flag *f, va_list *ap);
int				fpf_handler_wx(t_flag *f, va_list *ap);
char			*fpf_modifier_x(t_flag *f, va_list *ap);

int				fpf_handler_p(t_flag *f, va_list *ap);
int				fpf_handler_undefined(t_flag *f);

/*
** fpf_apply_flags.c
*/

void			fpf_space_plus_sharp(t_flag *f);
void			fpf_sharp(t_flag *f);
void			fpf_precision_string(t_flag *f);

/*
** fpf_display_numb.c
*/

void			fpf_precision_without_width(t_flag *f);
void			fpf_precision_numb(t_flag *f, int len);
void			fpf_zero_numb(t_flag *f);
void			fpf_minus_numb(t_flag *f);
void			fpf_width_numb(t_flag *f);

/*
** fpf_display_numb.c
*/

int				fpf_width_rest(t_flag *f);
void			fpf_display_arg(t_flag *f);
void			fpf_width_char(t_flag *f);
void			fpf_minus_char(t_flag *f);
void			fpf_zero_char(t_flag *f);

/*
** fpf_buff.c
*/

void			fpf_buf(char c, t_flag *f);
void			fpf_buf_null(t_flag *f);
void			fpf_display(t_flag *f);
void			fpf_bufset(void);

/*
** fpf_wildcard.c
*/

int				fpf_wildcard(t_flag *f, va_list *ap, int index);

#endif
