/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 21:02:11 by dgerard           #+#    #+#             */
/*   Updated: 2017/08/10 21:02:14 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void			print_string(t_flags *flags, va_list *arg)
{
	int		i;
	char	*string;
	int		spaces;
	int		length;

	i = 0;
	string = va_arg(*(arg), char *);
	if (!string)           //VVValso maybe make sure presicion and width dont apply to it, could be an issue
		string = "(null)"; //ya might need to declare this differently, unstable b/c not malloced?
	length = (int)ft_strlen(string);
	spaces = flags->width - length;
	if (flags->presicion < length && flags->presicion != -1)
		spaces = spaces + flags->presicion;
	while (!(flags->flag & 0b1) && spaces-- > 0)
		ft_putchar_mem(flags, ' ');
	while (string[i] != '\0')
	{
		if (flags->presicion != -1)
			if ((i + 1) > flags->presicion)
				break;
		ft_putchar_mem(flags, string[i++]);
	}
	while (flags->flag & 0b1 && spaces-- > 0)
		ft_putchar_mem(flags, ' ');
}

/*
void			print_pointer()
{

}
*/
