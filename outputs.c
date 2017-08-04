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

void				ft_putnbr_mem(t_flags *flags, intmax_t nbr, int base)
{
	int		isneg;
	int		power;

	isneg = (nbr < 0) ? -1 : 1;
	if (nbr == 0)
		ft_putchar_mem(flags, '0');
	while (nbr != 0)
	{
		ft_putchar_mem(flags, ((nbr % base) + '0') * isneg);
		nbr = nbr / base;
	}
}

void				ft_putunbr_mem(t_flags *flags, uintmax_t nbr, int base)
{
	int		alpha;

	print_prefix(flags);
	alpha = (flags->caps == true) ? '9' : 'Y';
	if (nbr == 0)
		ft_putchar_mem(flags, '0');
	while (nbr != 0)
	{
		if (nbr % base > 9)
			ft_putchar_mem(flags, ((nbr % base) + alpha));
		else
			ft_putchar_mem(flags, ((nbr % base) + '0'));
		nbr = nbr / base;
	}
}
