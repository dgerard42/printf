/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outputs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 17:38:58 by dgerard           #+#    #+#             */
/*   Updated: 2017/07/28 18:48:26 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_putchar_mem(t_flags *flags, char c)
{
	write(1, &c, 1);
	flags->written_chars++;
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

/*
void				ft_putnbr_mem(t_flags *flags, intmax_t nbr, int base)
{
	int			isneg;
	uintmax_t	power;

	isneg = (nbr < 0) ? -1 : 1;
	power = ft_power_ll(base, ft_numlen_ll(nbr, base));
	if (nbr == 0)
		ft_putchar_mem(flags, '0');
	while (nbr != 0 && power / base != 0)
	{
		ft_putchar_mem(flags, (nbr * isneg / (power / base)) + '0');
		nbr = nbr - isneg * (nbr * isneg / (power / base)) * (power / base);
		power = power / base;
	}
}
*/

void				ft_putnbr_mem(t_flags *flags, intmax_t nbr, int base)
{
	int			isneg;
	uintmax_t	power;

	isneg = (nbr < 0) ? -1 : 1;
	power = ft_power_ll(base, ft_numlen_ll(nbr, base));
	power = power / base; //dividing here intsead of just doing 10^1 allows single digits to not have leadng 0s
	if (nbr == 0)
		ft_putchar_mem(flags, '0');
	while (nbr != 0 && power != 0)
	{
		ft_putchar_mem(flags, ((nbr * isneg) / power) + '0');
		nbr = nbr - isneg * ((nbr * isneg) / power) * power;
		power = power / base;
	}
}
//delete ft_power_ull if it isn't needed
void				ft_putunbr_mem(t_flags *flags, uintmax_t nbr, unsigned int base)
{
	int			alpha;
	uintmax_t	power;

	print_prefix(flags);
	alpha = (flags->caps == true) ? '9' : 'Y';
 	power = ft_power_ull(base, (ft_numlen_ull(nbr, base) - 1));
	if (nbr == 0)
		ft_putchar_mem(flags, '0');
	while (nbr != 0 && power != 0)
	{
		if ((nbr / power) > 9)
			ft_putchar_mem(flags, (nbr / power) + alpha);
		else
			ft_putchar_mem(flags, (nbr / power) + '0');
		nbr = nbr - (nbr / power) * power;
		power = power / base;
	}
}

#include <limits.h>

/**/
int 				main(void)
{
	t_flags	flags;

	flags.caps = true;
	ft_putnbr_mem(&flags, 2, 10);
	printf("\n");
	ft_putnbr_mem(&flags, -42, 10);
	printf("\n");
	ft_putnbr_mem(&flags, 9223372036854775807, 10);
	printf("\n");
	ft_putnbr_mem(&flags, -9223372036854775807, 10);
	printf("\n");
	ft_putnbr_mem(&flags, -9223372036854775808, 10);
	printf("\n");
	ft_putnbr_mem(&flags, 9223372036854775807, 10);
	printf("\nunsigned VVV\n");
	ft_putunbr_mem(&flags, LLMAX, 10);
	printf("\n");
	ft_putunbr_mem(&flags, -LLMAX, 10);
	printf("\n");
	printf("%lu\n", -LLMAX);
	ft_putunbr_mem(&flags, 42, 16);
	printf("\n");
	ft_putunbr_mem(&flags, -42, 16);
	printf("\n");
	printf("%x\n", -42);
}
/**/
