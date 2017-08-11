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
t_spec		spec_functs[6]
{
	&print_char, &print_digit, &print_octal, &print_string, &print_unsigned,
	&print_hex, &print_pointer
};
*/
//rm some of these elifs if they aren't nesecary
void			typecast_unum(t_flags *flags, uintmax_t nbr, int base)
{
	if (flags->length == 4 || (flags->caps == true && flags->spec == 5))
		ft_putunbr_mem(flags, (unsigned long)nbr, base);
	else if (flags->length == 0)
		ft_putunbr_mem(flags, (unsigned int)nbr, base);
	else if (flags->length == 1)
		ft_putunbr_mem(flags, (unsigned char)nbr, base);
	else if (flags->length == 2)
		ft_putunbr_mem(flags, (unsigned short)nbr, base);
	else if (flags->length == 3 || flags->length == 5)
		ft_putunbr_mem(flags, nbr, base);
	else if (flags->length == 6)
		ft_putunbr_mem(flags, (size_t)nbr, base);
}

void			typecast_num(t_flags *flags, intmax_t nbr, int base)
{
	if (flags->length == 4 || (flags->caps == true && flags->spec == 5))
		ft_putnbr_mem(flags, (long int)nbr, base);
	else if (flags->length == 0)
		ft_putnbr_mem(flags, (int)nbr, base);
	else if (flags->length == 1)
		ft_putnbr_mem(flags, (signed char)nbr, base);
	else if (flags->length == 2)
		ft_putnbr_mem(flags, (short int)nbr, base);
	else if (flags->length == 3 || flags->length == 5)
		ft_putnbr_mem(flags, nbr, base);
	else if (flags->length == 6)
		ft_putnbr_mem(flags, (size_t)nbr, base);
}

void			print_signed(t_flags *flags, va_list *arg, int base)
{
	long long 	i;
	int			padding;

	i = va_arg(*(arg), intmax_t);
	if (flags->width == 0)
		padding = flags->presicion - ft_numlen_ll(i, base);
	else
		padding = flags->width - ft_numlen_ll(i, base);
	if (flags->flag & 0b1)
		typecast_num(flags, i, base);
	while (padding-- > 0)
	{
		if (flags->flag & 0b10000 && !(flags->flag & 0b1))
			ft_putchar_mem(flags, '0');
		else
			ft_putchar_mem(flags, ' ');
	}
	if (!(flags->flag & 0b1) || flags->presicion > ft_numlen_ll(i, base))
		typecast_num(flags, i, base);
}


void			print_unsigned(t_flags *flags, va_list *arg, int base)
{
	long long 	i;
	int			padding;

	i = va_arg(*(arg), uintmax_t);
	if (flags->width == 0)
		padding = flags->presicion - ft_numlen_ull(i, base);
	else
		padding = flags->width - ft_numlen_ull(i, base);
	if (flags->flag & 0b1000)
		padding = padding - 2;
	if (flags->flag & 0b1)
		typecast_unum(flags, i, base);
	while (padding-- > 0)
	{
		if (flags->flag & 0b10000 || flags->presicion > 0)
			ft_putchar_mem(flags, '0');
		else
			ft_putchar_mem(flags, ' ');
	}
	if (!(flags->flag & 0b1) || flags->presicion > ft_numlen_ull(i, base))
		typecast_unum(flags, i, base);
}

void			parse_args(t_flags *flags, va_list *arg)
{
//	printf("flag%d, width%d, presicion%d, length%d, spec%d, written_chars%d\n",
//		flags->flag, flags->width, flags->presicion, flags->length, flags->spec, flags->written_chars);
	if(flags->spec == 1)
		print_char(flags, arg);
	else if(flags->spec == 2)
		print_signed(flags, arg, 10);
	else if(flags->spec == 3)
		print_unsigned(flags, arg, 8);
	else if(flags->spec == 4)
		print_string(flags, arg);
	else if(flags->spec == 6)
		print_unsigned(flags, arg, 16);
	else if (flags->spec == 5)
		print_unsigned(flags, arg, 10);
}
