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
 	if (flags->flag & 0b1)
		ft_putchar_mem(c);
	while (flags->width-- > 1)
		ft_putchar_mem(' ');
	if (!(flags->flag & 0b1))
		ft_putchar_mem(c);
}

void			print_digit(t_flags *flags, int i)
{
	int pres_offset;

	pres_offset = 0;
	if (flags->flag & 0b10)
		ft_putchar_mem((i >= 0) ? '+' : '-');
	if (flags->flag & 0b100 && i >= 0 && flags->width > 0)
		ft_putchar_mem(' ');
	if (flags->flag & 0b1 || flags->presicion <= ft_numlen(i))
		ft_putnbr_mem(i);
	while (flags->width-- > 1)
		(flags->flag & 0b10000 ? ft_putchar_mem('0') : ft_putchar_mem(' ');
	while (flags->presicion - ft_numlen(i) - pres_offset > 0)
	{
		ft_putchar_mem('0');
		pres_offset++;
	}
	if (!(flags->flag & 0b1) || flags->presicion > ft_numlen(i))
		ft_putnbr_mem(i);
}

/*
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
*/

void			parse_args(t_flags *flags, va_list *arg)
{
	int	i;

	i = 0;
	if(flags->specifier == 1)
	{
		i = va_arg(*(arg), int);
		print_char(flags, i);
	}
}
