/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 18:11:47 by ademenet          #+#    #+#             */
/*   Updated: 2016/04/07 18:11:53 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     ft_count_words(char *s)
{
    int	i;
    int	is_word;

    i = 0;
    is_word = 0;
    while (*s)
    {
        if (is_word == 0 && *s != c)
        {
            is_word = 1;
            i++;
        }
        else if (is_word == 1 && *s == c)
            is_word = 0;
        s++;
    }
    return (i);
}
