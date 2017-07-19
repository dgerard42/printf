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


const char 			*check_flags(const char *format, t_arg *arg)
{
	if (*format == '-')
		arg->flag = 1;
	else if (*format == '+')
		arg->flag = 2;
	else if (*format == ' ')
		arg->flag = 3;
	else if (*format == '#')
		arg->flag = 4;
	else if (*format == '0')
		arg->flag = 5;
	else
		arg->flag = 0;
	if (arg->flag != 0)
		format++;
	return (format);
}

const char 			*check_width(const char *format, t_arg *arg)
{
	if (ft_isdigit((int)*format)
		arg->width = ft_atoi(*format);
	else if (*format == '*')
		arg->width = -1;
	else
		arg->width = -2;
	if (arg->width == -2)
		format++;
}

const char 			*check_presicion(const char *format, t_arg *arg)
{

}

const char 			*check_length(const char *format, t_arg *arg)
{

}

const char 			*check_specifier(const char *format, t_arg *arg)
{

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
	}
}
