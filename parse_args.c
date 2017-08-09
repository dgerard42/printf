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

void			typecast_num(t_flags *flags, uintmax_t nbr, int base)
{
	if ((flags->spec == 3 || flags->spec == 5 || flags->spec == 6) && flags->length == 0)
		ft_putunbr_mem(flags, (unsigned int)nbr, base);
	else if ((flags->spec == 3 || flags->spec == 5 || flags->spec == 6) && flags->length == 1)
		ft_putunbr_mem(flags, (unsigned char)nbr, base);
	else if ((flags->spec == 3 || flags->spec == 5 || flags->spec == 6) && flags->length == 2)
		ft_putunbr_mem(flags, (unsigned short)nbr, base);
	else if ((flags->spec == 3 || flags->spec == 5 || flags->spec == 6) && (flags->length == 3 || flags->length == 5))
		ft_putunbr_mem(flags, nbr, base);
	else if ((flags->spec == 3 || flags->spec == 5 || flags->spec == 6) && flags->length == 4)
		ft_putunbr_mem(flags, (unsigned long)nbr, base);
	else if ((flags->spec == 3 || flags->spec == 5 || flags->spec == 6) && flags->length == 6)
		ft_putunbr_mem(flags, (size_t)nbr, base);
}

//to speed things up, stop putting function calls in conditional statements
void			print_signed(t_flags *flags, va_list *arg, int base)
{
	long long 	i;
	int			padding;

	i = va_arg(*(arg), intmax_t);
	padding = (flags->width == 0) ? flags->presicion - ft_numlen_ll(i, base) : flags->width - ft_numlen_ll(i, base);
	if (flags->flag & 0b10 && i >= 0)
		ft_putchar_mem(flags, '+');
	if (i < 0)
		ft_putchar_mem(flags, '-');
	if (!(flags->flag & 0b10) && flags->flag & 0b100 && i >= 0)
		ft_putchar_mem(flags, ' ');
	if (flags->flag & 0b1)
		ft_putnbr_mem(flags, i, base);
	while (padding-- > 0)
		(flags->flag & 0b10000 && !(flags->flag & 0b1)) ? ft_putchar_mem(flags, '0') : ft_putchar_mem(flags, ' ');
		//(flags->flag & 0b10000 || flags->presicion > 0) ? ft_putchar_mem(flags, '0') : ft_putchar_mem(flags, ' ');
	if (!(flags->flag & 0b1) || flags->presicion > ft_numlen_ll(i, base))
		ft_putnbr_mem(flags, i, base);
}

void			print_unsigned(t_flags *flags, va_list *arg, int base)
{
	long long 	i;
	int			padding;

	i = va_arg(*(arg), uintmax_t);
	padding = (flags->width == 0) ? flags->presicion - ft_numlen_ull(i, base) : flags->width - ft_numlen_ull(i, base);
	if (flags->flag & 0b1000)
		padding = padding - 2;
//	if (!(flags->flag & 0b10) && flags->flag & 0b100 && i >= 0)
//		ft_putchar_mem(flags, ' ');
	if (flags->flag & 0b1)
		typecast_num(flags, i, base);
	while (padding-- > 0)
		(flags->flag & 0b10000 || flags->presicion > 0) ? ft_putchar_mem(flags, '0') : ft_putchar_mem(flags, ' ');
	if (!(flags->flag & 0b1) || flags->presicion > ft_numlen_ull(i, base))
		typecast_num(flags, i, base);
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
void			print_pointer()
{

}
*/


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
