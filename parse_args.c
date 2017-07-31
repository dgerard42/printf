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

void			print_char(t_flags *flags, va_list *arg)
{
	char	c;

	c = va_arg(*(arg), int);
 	if (flags->flag & 0b1)
		ft_putchar_mem(flags, c);
	while (flags->width-- > 1)
		ft_putchar_mem(flags, ' ');
	if (!(flags->flag & 0b1))
		ft_putchar_mem(flags, c);
}

void			print_prefix(t_flags *flags)
{
	if (flags->flag & 0b1000)
	{
		if (flags->specifier == 3 || flags->specifier == 6)
			ft_putchar_mem(flags, '0');
		if (flags->specifier == 6)
			(flags->caps == true) ? ft_putchar_mem(flags, 'X') : ft_putchar_mem(flags, 'x');
	}
}
//to speed things up, stop putting function calls in conditional statements
void			print_digit(t_flags *flags, va_list *arg, int base)
{
	int	i;
	int	padding;

	i = va_arg(*(arg), int);
	padding = (flags->width == 0) ? flags->presicion - ft_numlen(i, base) : flags->width - ft_numlen(i, base);
	if (flags->flag & 0b10 && i >= 0)
		ft_putchar_mem(flags, '+');
	if (!(flags->flag & 0b10) && flags->flag & 0b100 && i >= 0)
		ft_putchar_mem(flags, ' ');
	if (flags->flag & 0b1)
	{
		print_prefix(flags);
		ft_putnbr_mem(flags, i, base);
	}
	while (padding-- > 0)
		(flags->flag & 0b10000 || flags->presicion > 0) ? ft_putchar_mem(flags, '0') : ft_putchar_mem(flags, ' ');
	if (!(flags->flag & 0b1) || flags->presicion > ft_numlen(i, base))
	{
		print_prefix(flags);
		ft_putnbr_mem(flags, i, base);
	}
}

void			print_string(t_flags *flags, va_list *arg)
{
	int		i;
	char	*string;
	int		length;

	i = 0;
	string = va_arg(*(arg), char *);
	length = (int)ft_strlen(string);
	while (!(flags->flag & 0b1) && flags->width-- - length > 0)
		ft_putchar_mem(flags, ' ');
	while (string[i] != '\0')
	{
		if (flags->presicion != -1)
			if ((i + 1) > flags->presicion)
				break;
		ft_putchar_mem(flags, string[i++]);
	}
	while (flags->flag & 0b1 && flags->width-- - length > 0)
		ft_putchar_mem(flags, ' ');
}

/*
void			print_unsigned()
{

}
void			print_pointer()
{

}
*/

void			parse_args(t_flags *flags, va_list *arg)
{
//	printf("flag%d, width%d, presicion%d, length%d, specifier%d, written_chars%d\n",
//		flags->flag, flags->width, flags->presicion, flags->length, flags->specifier, flags->written_chars);
	if(flags->specifier == 1)
		print_char(flags, arg);
	else if(flags->specifier == 2)
		print_digit(flags, arg, 10);
	else if(flags->specifier == 3)
		print_digit(flags, arg, 8);
	else if(flags->specifier == 4)
		print_string(flags, arg);
	else if(flags->specifier == 6)
		print_digit(flags, arg, 16);
}
