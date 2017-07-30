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

char					base_assign(int num)
{
	int		i;
	char	*alnums;

	i = 0;
	alnums = "0123456789ABCDEF";
	while (num-- > 0)
		i++;
	return (alnums[i]);
}

//add base option and make like itoa
void				ft_putnbr_mem(t_flags *flags, int nbr, int base)
{
	bool	max;
	char	last;

	max = false;
	if (nbr == -2147483648)
	{
		max = true;
		nbr += base;
		last = base_assign(abs(nbr % base));
		nbr -= base;
		ft_putnbr_mem(flags, nbr / base, base);
	}
	else if (nbr < 0)
	{
		ft_putchar_mem(flags, '-');
		nbr = -nbr;
		if (nbr / base != 0)
			ft_putnbr_mem(flags, nbr / base, base);
		ft_putchar_mem(flags, base_assign(nbr % base));
	}
	else
	{
		if (nbr > (base - 1))
			ft_putnbr_mem(flags, nbr / base, base);
		ft_putchar_mem(flags, base_assign(nbr % base));
	}
	if (max == true)
		ft_putchar_mem(flags, last);
}
