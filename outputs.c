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

void				ft_putnbr_mem(t_flags *flags, int nbr)
{
	if (nbr == -2147483648)
	{
		ft_putnbr_mem(flags, nbr / 10);
		ft_putchar_mem(flags, '8');
	}
	else if (nbr < 0)
	{
		ft_putchar_mem(flags, '-');
		nbr = -nbr;
		if (nbr / 10 != 0)
			ft_putnbr_mem(flags, nbr / 10);
		ft_putchar_mem(flags, (nbr % 10) + '0');
	}
	else
	{
		if (nbr > 9)
			ft_putnbr_mem(flags, nbr / 10);
		ft_putchar_mem(flags, (nbr % 10) + '0');
	}
}
