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
uintmax_t			typecast_unum(t_flags *flags, uintmax_t nbr)
{
	if (flags->spec == 7)
		return (nbr);
	else if (flags->length == 4 || (flags->caps == true && flags->spec == 5))
		nbr = (unsigned long)nbr;
	else if (flags->length == 0)
		nbr = (unsigned int)nbr;
	else if (flags->length == 1)
		nbr = (unsigned char)nbr;
	else if (flags->length == 2)
		nbr = (unsigned short)nbr;
	else if (flags->length == 6)
		nbr = (size_t)nbr;
	return (nbr);
}

intmax_t			typecast_num(t_flags *flags, intmax_t nbr)
{
	if (flags->length == 4 || (flags->caps == true && flags->spec == 2))
		nbr = (long int)nbr;
	else if (flags->length == 0)
		nbr = (int)nbr;
	else if (flags->length == 1)
		nbr = (signed char)nbr;
	else if (flags->length == 2)
		nbr = (short int)nbr;
	else if (flags->length == 6)
		nbr = (size_t)nbr;
	return (nbr);
}

void			print_signed(t_flags *flags, va_list *arg, int base)
{
	intmax_t	nbr;
	int			zeroes;
	int			spaces;

	zeroes = 0;
	spaces = 0;
	nbr = va_arg(*(arg), intmax_t);
	nbr = typecast_num(flags, nbr);
	if (flags->presicion >= ft_numlen_ll(nbr, base))
		zeroes = flags->presicion - ft_numlen_ll(nbr, base);
	else if (flags->flag & 0b10000 && flags->width > 0 && !(flags->flag & 0b1))
	{
		zeroes = flags->width - ft_numlen_ll(nbr, base);
		if (nbr < 0 || flags->flag & 0b10 || flags->flag & 0b100)
			zeroes--;
	}
	spaces = flags->width - ft_numlen_ll(nbr, base) - zeroes;
	if (nbr == 0 && flags->presicion == 0)
		spaces++;
	if (nbr < 0 || flags->flag & 0b10 || flags->flag & 0b100)
			spaces--;
	while (!(flags->flag & 0b1) && spaces-- > 0)
		ft_putchar_mem(flags, ' ');
	print_sign(flags, nbr);
	while (zeroes-- > 0)
		ft_putchar_mem(flags, '0');
	ft_putnbr_mem(flags, nbr, base);
	while (flags->flag & 0b1 && spaces-- > 0)
		ft_putchar_mem(flags, ' ');
}
//shit!! I think I can combine these two functions when you have to break them apart.
void			print_unsigned(t_flags *flags, va_list *arg, int base)
{
	uintmax_t 	nbr;
	int			zeroes;
	int			spaces;

	zeroes = 0;
	spaces = 0;
	nbr = va_arg(*(arg), uintmax_t);
	nbr = typecast_unum(flags, nbr);
	if (flags->presicion >= ft_numlen_ull(nbr, base))
		zeroes = flags->presicion - ft_numlen_ull(nbr, base);
	else if (flags->flag & 0b10000 && flags->width > 0 && !(flags->flag & 0b1))
	{
		zeroes = flags->width - ft_numlen_ull(nbr, base);
		if ((flags->flag & 0b1000 && flags->spec == 6) || flags->spec == 7)
			zeroes = zeroes - 2;
		else if (flags->flag & 0b1000 && flags->spec == 3)
			zeroes--;
	}
	spaces = flags->width - ft_numlen_ll(nbr, base) - zeroes;
	if (nbr == 0 && flags->presicion == 0)
		spaces++;
	if ((flags->flag & 0b1000 && flags->spec == 6) || flags->spec == 7)
		spaces = spaces - 2;
	else if (flags->flag & 0b1000 && flags->spec == 3)
		spaces--;
	while (!(flags->flag & 0b1) && spaces-- > 0)
		ft_putchar_mem(flags, ' ');
	print_prefix(flags, nbr);
	while (zeroes-- > 0)
		ft_putchar_mem(flags, '0');
	ft_putunbr_mem(flags, nbr, base);
	while (flags->flag & 0b1 && spaces-- > 0)
		ft_putchar_mem(flags, ' ');
}

void			parse_args(t_flags *flags, va_list *arg)
{
//	printf("flag%d, width%d, presicion%d, length%d, spec%d, written_chars%d\n",
//		flags->flag, flags->width, flags->presicion, flags->length, flags->spec, flags->written_chars);
	if(flags->spec == 1 || flags->spec == 8)
		print_char(flags, arg);
	else if(flags->spec == 2)
		print_signed(flags, arg, 10);
	else if(flags->spec == 3)
		print_unsigned(flags, arg, 8);
	else if(flags->spec == 4)
		print_string(flags, arg);
	else if(flags->spec == 6 || flags->spec == 7)
		print_unsigned(flags, arg, 16);
	else if (flags->spec == 5)
		print_unsigned(flags, arg, 10);
}
