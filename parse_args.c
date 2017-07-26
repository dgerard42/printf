/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 17:17:59 by dgerard           #+#    #+#             */
/*   Updated: 2017/07/23 17:18:19 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
t_specifier		spec_functs[6]
{
	&print_char, &print_digit, &print_octal, &print_string, &print_unsigned,
	&print_hex, &print_pointer
};
*/

void			print_char(t_flags *flags, char c)
{
	while (flags->width-- > 0 && flags->flag != )
	{

	}
	ft_putchar(c);
}

void			print_digit(t_flags *flags, int i)
{
	ft_putnbr(int i);
}

void			print_string(t_flags *flags, char *s)
{
	ft_putstr(char *s);
	//except you'll have to stop mid string sometimes
}

void			print_octal()
{

}

void			print_unsigned()
{

}

void			print_hex()
{

}

void			print_pointer()
{

}

void			parse_args(t_flags *flags, )
{
	va_list arg;
	va_start (arg, format);

	//route into functions here,
	if()

	va_end(arg);
}
