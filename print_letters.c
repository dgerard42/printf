/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_letters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 21:02:11 by dgerard           #+#    #+#             */
/*   Updated: 2017/08/14 20:43:36 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			print_char(t_flags *flags, va_list *arg)
{
	char	c;

	if (flags->spec != 8)
		c = va_arg(*(arg), int);
	else
		c = flags->invalid_spec;
	if (flags->flag & 0b1)
		ft_putchar_mem(flags, c);
	while (flags->width-- > 1)
		ft_putchar_mem(flags, ' ');
	if (!(flags->flag & 0b1))
		ft_putchar_mem(flags, c);
}

int				spaces_calc(t_flags *flags, char *string)
{
	int spaces;
	int length;

	length = (int)ft_strlen(string);
	spaces = flags->width - length;
	if (flags->presicion < length && flags->presicion != -1)
		spaces = spaces - (flags->presicion - length);
	return (spaces);
}

void			print_string(t_flags *flags, va_list *arg)
{
	int		i;
	char	*string;
	int		spaces;

	i = 0;
	string = va_arg(*(arg), char *);
	if (!string)
	{
		ft_putstr("(null)");
		flags->written_chars += 6;
	}
	else
	{
		spaces = spaces_calc(flags, string);
		while (!(flags->flag & 0b1) && spaces-- > 0)
			ft_putchar_mem(flags, ' ');
		while (string[i] != '\0')
		{
			if (flags->presicion != -1)
				if ((i + 1) > flags->presicion)
					break ;
			ft_putchar_mem(flags, string[i++]);
		}
		while (flags->flag & 0b1 && spaces-- > 0)
			ft_putchar_mem(flags, ' ');
	}
}
