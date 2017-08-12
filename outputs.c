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

void			print_sign(t_flags *flags, intmax_t nbr)
{
	if (nbr < 0)
		ft_putchar_mem(flags, '-');
	else if (flags->flag & 0b10 && nbr >= 0)
		ft_putchar_mem(flags, '+');
	else if (!(flags->flag & 0b10) && flags->flag & 0b100 && nbr >= 0)
		ft_putchar_mem(flags, ' ');
}

void			print_prefix(t_flags *flags, uintmax_t nbr)
{
	if (flags->flag & 0b1000 && nbr != 0)
	{
		if (flags->spec == 3 || flags->spec == 6)
			ft_putchar_mem(flags, '0');
		if (flags->spec == 6)
			(flags->caps == true) ? ft_putchar_mem(flags, 'X') : ft_putchar_mem(flags, 'x');
	}
}

void				ft_putnbr_mem(t_flags *flags, intmax_t nbr, int base)
{
	int			isneg;
	uintmax_t	power;

	isneg = (nbr < 0) ? -1 : 1;
	power = ft_power_ll(base, ft_numlen_ll(nbr, base));
	power = power / base; //dividing here intsead of just doing 10^1 allows single digits to not have leadng 0s
	while (nbr != 0 && power != 0)
	{
		ft_putchar_mem(flags, ((nbr * isneg) / power) + '0');
		nbr = nbr - isneg * ((nbr * isneg) / power) * power;
		power = power / base;
	}
	while (nbr == 0 && power > 0)
	{
		if (flags->presicion != 0)
			ft_putchar_mem(flags, '0');
		power = power / base;
	}
}
//delete ft_power_ull if it isn't needed
void				ft_putunbr_mem(t_flags *flags, uintmax_t nbr, unsigned int base)
{
	int			alpha;
	uintmax_t	power;

	alpha = (flags->caps == true) ? '7' : 'W';
 	power = ft_power_ull(base, (ft_numlen_ull(nbr, base) - 1));
	while (nbr != 0 && power != 0)
	{
		if ((nbr / power) > 9)
			ft_putchar_mem(flags, (nbr / power) + alpha);
		else
			ft_putchar_mem(flags, (nbr / power) + '0');
		nbr = nbr - (nbr / power) * power;
		power = power / base;
	}
	while (nbr == 0 && power > 0)
	{
		if (flags->presicion != 0 || (flags->flag & 0b1000 && flags->spec == 3))
			ft_putchar_mem(flags, '0');
		power = power / base;
	}
}
/*
int 				main(void)
{
	t_flags	flags;

	flags.caps = false;
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
	ft_putunbr_mem(&flags, 2, 10);
	printf("\n");
	ft_putunbr_mem(&flags, 4242424242, 10);
	printf("\n");
	printf("%u\n", 4242424242);
	ft_putunbr_mem(&flags, -42, 16);
	printf("\n");
	printf("%x\n", -42);
	ft_putunbr_mem(&flags, ULLMAX, 16);
	printf("\n");
	printf("%llx\n", ULLMAX);
}
*/
