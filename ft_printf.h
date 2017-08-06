/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 11:32:52 by dgerard           #+#    #+#             */
/*   Updated: 2017/07/18 11:32:54 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_H
# define FTPRINTF_H //change the name of the .h file

# include "libft/libft.h"
# include <stdarg.h>
# include <stdbool.h>
//# include <stdlib.h>
# include <stdio.h> //REMOVE THIS EVENTUALLY!!!!!!!!

//delete these if you decide not to use them in the code itself
# define MINUS				0b1
# define PLUS				0b10
# define SPACE				0b100
# define HASHTAG			0b1000
# define ZERO				0b10000

typedef	struct		s_flags
{
	unsigned char	flag;
	int				width;
	int			 	presicion;
	int				length;
	int				specifier;
	bool			caps;
	int				written_chars;
}					t_flags;

//typedef char	*(*t_spec_functs)(size_t *, va_list);

int				ft_printf(const char *format, ...);
void			parse_args(t_flags *flags, va_list *arg);
void			ft_putchar_mem(t_flags *flags, char c);
void			ft_putnbr_mem(t_flags *flags, intmax_t nbr, int base);
void			ft_putunbr_mem(t_flags *flags, uintmax_t nbr, int base);

#endif
