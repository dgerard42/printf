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

char					base_assign(int num, bool caps)
{
	int		i;
	char	*alnums_caps;
	char	*alnums_lower;

	i = 0;
	alnums_lower = "0123456789abcdef";
	alnums_caps = "0123456789ABCDEF";
	while (num-- > 0)
		i++;
	return ((caps == true) ? alnums_caps[i] : alnums_lower[i]);
}

void				ft_putnbr_mem(t_flags *flags, int nbr, int base)
{
	bool	max;
	char	last;

	max = (nbr == -2147483648) ? true : false;
	if (nbr == -2147483648)
	{
		nbr += base;
		last = base_assign(abs(nbr % base), flags->caps);
		nbr -= base;
		ft_putnbr_mem(flags, nbr / base, base);
	}
	else if (nbr < 0)
	{
		ft_putchar_mem(flags, '-');
		nbr = -nbr;
		if (nbr / base != 0)
			ft_putnbr_mem(flags, nbr / base, base);
		ft_putchar_mem(flags, base_assign(nbr % base, flags->caps));
	}
	else
	{
		if (nbr > (base - 1))
			ft_putnbr_mem(flags, nbr / base, base);
		ft_putchar_mem(flags, base_assign(nbr % base, flags->caps));
	}
	if (max == true)
		ft_putchar_mem(flags, last);
}
