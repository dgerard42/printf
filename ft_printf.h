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
#include <limits.h> //mYBE USE these premade limits
# include <stdio.h> //REMOVE THIS EVENTUALLY!!!!!!!!

//delete these if you decide not to use them in the code itself
# define MINUS				0b1
# define PLUS				0b10
# define SPACE				0b100
# define HASHTAG			0b1000
# define ZERO				0b10000

# define ULLMAX			18446744073709551615//these were just for testing, rm eventually
# define LLMAX			9223372036854775807

typedef	struct		s_flags
{
	unsigned char	flag;
	int				width;
	int			 	presicion;
	int				length;
	int				spec;
	bool			caps;
	int				written_chars;
}					t_flags;

//typedef char	*(*t_spec_functs)(size_t *, va_list);
int				ft_printf(const char *format, ...);
void			parse_args(t_flags *flags, va_list *arg);
void			ft_putchar_mem(t_flags *flags, char c);
void			ft_putnbr_mem(t_flags *flags, intmax_t nbr, int base);
void			ft_putunbr_mem(t_flags *flags, uintmax_t nbr, unsigned int base);
void			print_char(t_flags *flags, va_list *arg);
void			print_string(t_flags *flags, va_list *arg);
void			print_sign(t_flags *flags, intmax_t nbr);
void			print_prefix(t_flags *flags, uintmax_t);

#endif
