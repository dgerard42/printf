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


const char 			*check_flags(const char *format, t_arg *arg)
{
	arg->flag = 0b00000000;
	while (*format == '-' || *format == '+' || *format == ' ' ||
		*format == '#' || *format == '0')
	{
		if (*format == '-' && check_dubs(format, '-'))
			arg->flag += 0b00000001;
		if (*format == '+' && check_dubs(format, '+'))
			arg->flag += 0b00000010;
		if (*format == ' ' && check_dubs(format, ' '))
			arg->flag += 0b00000100;
		if (*format == '#' && check_dubs(format, '#'))
			arg->flag += 0b00001000;
		if (*format == '0' && check_dubs(format, '0'))
			arg->flag += 0b00010000;
		format++;
	}
	return (format);
}

const char 			*check_width(const char *format, t_arg *arg)
{
	arg->width = -2;
	if (ft_isdigit((int)*format)
		arg->width = ft_atoi(*format);
	else if (*format == '*')
		arg->width = -1;
	if (arg->width != -2)
		format++;
	return (format);
}

const char 			*check_presicion(const char *format, t_arg *arg)
{
	arg->presicion = -2;
	if (*format == '.')
		format++;
	if (ft_isdigit((int)*format)
		arg->presicion = ft_atoi(*format);
	else if (*format == '*')
		arg->presicion = -1;
	if (arg->presicion != -2)
		format++;
	return (format);
}

const char 			*check_length(const char *format, t_arg *arg)
{

}

const char 			*check_specifier(const char *format, t_arg *arg)
{
	//c, d or i, e, E, f, g, G, o, s, u, x, X, p, n, %
	if (*format == 'c')	
	else if (*format == 'd' || *format == 'i')
	else if (*format == 'e')
	else if (*format == 'E')
	else if (*format == 'f')
	else if (*format == 'g')
	else if (*format == 'G')
	else if (*format == 'o')
	else if (*format == 's')
	else if (*format == 'u')
	else if (*format == 'x')
	else if (*format == 'X')
	else if (*format == 'p')
	else if (*format == 'n')
	else if (*format == '%')
	else
		error. theres a fucking error.
}

const char 			*print_string(const char *format)
{
	while (*format != '%' && *format)
		ft_putchar(*format++);
	format++;
	return(format);
}

int					ft_printf(const char *format, ...)
{
	t_arg;

// make sure the format string is null terminated
	while (*format)
	{
		format = print_string(format);
		format = check_flags(format, &arg);
		format = check_width(format, &arg);
		format = check_presicion(format, &arg);
		format = check_length(format, &arg);
		format = check_specifier(format, &arg);
		//here get the actual next argument and process it according to info stored in struct
	}
}
