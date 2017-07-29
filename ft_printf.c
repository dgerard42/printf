/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 11:33:39 by dgerard           #+#    #+#             */
/*   Updated: 2017/07/18 11:33:44 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int				check_dubs(const char *format, char c)
{
	while (*format == '-' || *format == '+' || *format == ' ' ||
		*format == '#' || *format == '0')
	{
		format++;
		if (*format == c)
			return (0);
	}
	return (1);
}

const char 			*check_flags(const char *format, t_flags *flags)
{
	flags->flag = 0b0000000;
	while (*format == '-' || *format == '+' || *format == ' ' ||
		*format == '#' || *format == '0')
	{
		if (*format == '-' && check_dubs(format, '-'))
			flags->flag += 0b00000001;
		if (*format == '+' && check_dubs(format, '+'))
			flags->flag += 0b00000010;
		if (*format == ' ' && check_dubs(format, ' '))
			flags->flag += 0b00000100;
		if (*format == '#' && check_dubs(format, '#'))
			flags->flag += 0b00001000;
		if (*format == '0' && check_dubs(format, '0'))
			flags->flag += 0b00010000;
		format++;
	}
	return (format);
}

//try doubling up functions for width and presicion
const char 			*check_width_presicion(const char *format, t_flags *flags)
{
	flags->width = -1;
	flags->presicion = -1;
	if (ft_isdigit((int)*format))
		flags->width = ft_atoi(format);
	if (flags->width != -1)
		format++;
	if (*format == '.')
		format++;
	if (ft_isdigit((int)*format))
		flags->presicion = ft_atoi(format);
	if (flags->presicion != -1)
		format++;
	return (format);
}

/*
const char 			*check_length(const char *format, t_flags *flags)
{
	if (*format == 'h' && *format + 1 == 'h')
	if (*format == 'h' && *format + 1 != 'h')
	if (*format == 'l' && *format + 1 == 'l')
	if (*format == 'l' && *format + 1 != 'l')
	if (*format == 'j')
	if (*format == 'z')
}
*/

const char 			*check_specifier(const char *format, t_flags *flags)
{
	flags->specifier = 0;
	if (*format == 'c'|| *format == 'C')
		flags->specifier = 1;
	else if (*format == 'd' || *format == 'i' || *format == 'D')
		flags->specifier = 2;
	else if (*format == 'o' || *format == 'O')
		flags->specifier = 3;
	else if (*format == 's' || *format == 'S')
		flags->specifier = 4;
	else if (*format == 'u' || *format == 'U')
		flags->specifier = 5;
	else if (*format == 'x' || *format == 'X')
		flags->specifier = 6;
	else if (*format == 'p')
		flags->specifier = 7;
	if (flags->specifier != 0)
		format++;
	return (format);
}

const char 			*print_format_string(const char *format, t_flags *flags)
{
	while (*format != '%' && *format)
		ft_putchar_mem(flags, *format++);
	if (*format == '%' && *format + 1 == '%')
	{
		ft_putchar_mem(flags, '%');
		format++;
	}
	if (*format)
		format++;
	return(format);
}

int					ft_printf(const char *format, ...)
{
	t_flags flags;
	va_list arg;
	va_start (arg, format);

	flags.written_chars = 0;
// make sure the format string is null terminated
	while (*format)
	{
		format = print_format_string(format, &flags);
		format = check_flags(format, &flags);
		format = check_width_presicion(format, &flags);
	//	format = check_length(format, &flags);
		format = check_specifier(format, &flags);
		parse_args(&flags, &arg);
	//  make sure you reset the flags struct on each reiteration of the ft
	}
	va_end(arg);
	return (flags.written_chars);
}
