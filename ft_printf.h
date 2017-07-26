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
# define FTPRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef	struct		s_flags
{
	unsigned char	flag;
	int				width;
	int			 	presicion;
	unsigned char	length;
	int				specifier;
}					t_flags;

//typedef char	*(*t_spec_functs)(size_t *, va_list);

int			ft_printf(const char *format, ...);
void			parse_args(t_flags *flags, va_list *arg);

#endif
