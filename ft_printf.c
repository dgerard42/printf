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
		else if (*format == '+' && check_dubs(format, '+'))
			flags->flag += 0b00000010;
		else if (*format == ' ' && check_dubs(format, ' '))
			flags->flag += 0b00000100;
		else if (*format == '#' && check_dubs(format, '#'))
			flags->flag += 0b00001000;
		else if (*format == '0' && check_dubs(format, '0'))
			flags->flag += 0b00010000;
		format++;
	}
	return (format);
}

const char 			*check_width_presicion(const char *format, t_flags *flags)
{
	flags->width = 0;
	flags->presicion = -1;
	if (ft_isdigit((int)*format))
		flags->width = ft_atoi(format);
	while (flags->width != 0 && ft_isdigit((int)*format))
		format++;
	if (*format == '.')
	{
		flags->presicion = 0;
		format++;
	}
	if (ft_isdigit((int)*format))
		flags->presicion = ft_atoi(format);
	while (flags->presicion != -1 && ft_isdigit((int)*format))
		format++;
	return (format);
}

const char 			*check_length(const char *format, t_flags *flags)
{
	flags->length = 0;
	while (*format == 'h' || *format == 'l' || *format == 'j' || *format == 'z')
	{
		if (*format == 'h' && *(format + 1) == 'h')
			flags->length = 1;
		else if (*format == 'h' && *(format + 1) != 'h')
			flags->length = 2;
		else if (*format == 'l' && *(format + 1) == 'l')
			flags->length = 3;
		else if (*format == 'l' && *(format + 1) != 'l')
			flags->length = 4;
		else if (*format == 'j')
			flags->length = 5;
		else if (*format == 'z')
			flags->length = 6;
		if (flags->length == 1 || flags->length == 3)
			format++;
		if(flags->length != 0)
			format++;
	}
	return (format);
}

const char 			*check_specifier(const char *format, t_flags *flags)
{
	flags->spec = 0;
	if (*format == 'c'|| *format == 'C')
		flags->spec = 1;
	else if (*format == 'd' || *format == 'i' || *format == 'D')
		flags->spec = 2;
	else if (*format == 'o' || *format == 'O')
		flags->spec = 3;
	else if (*format == 's' || *format == 'S')
		flags->spec = 4;
	else if (*format == 'u' || *format == 'U')
		flags->spec = 5;
//	else if (*format == 'x' || *format == 'X')
//		flags->spec = 6;
	else if (*format == 'p')
		flags->spec = 7;
	else if (*format == '%')
		flags->spec = 8;
	flags->caps = (*format >='A' && *format <= 'Z') ? true : false;
	return (format);
}

const char 			*print_format_string(const char *format, t_flags *flags)
{
	while (*format != '%' && *format)
		ft_putchar_mem(flags, *format++);
	if (*format && *format == '%')
		format++;
	return (format);
}

int					ft_printf(const char *format, ...)
{
	t_flags flags;
	va_list arg;
	va_start (arg, format);

	flags.written_chars = 0;
// make sure the format string is null terminated
//to make this code faster, figure out how to skip these functions if you don't need them
	while (*format)
	{
		format = print_format_string(format, &flags);
		format = check_flags(format, &flags);
		format = check_width_presicion(format, &flags);
		format = check_length(format, &flags);
		format = check_specifier(format, &flags);
		if (flags.spec != 0)
			parse_args(&flags, &arg);
		if (*format)
			format++;
	//  make sure you reset the flags struct on each new parameter
	}
	va_end(arg);
	return (flags.written_chars);
}
