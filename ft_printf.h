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

//# include "libft/libft.h"

typedef	struct		s_flags
{
	unsigned char	flag;
	int				width;
	int			 	presicion;
	unsigned char	length;
	int				specifier;
}					t_flags;

int			ft_printf(const char *format, ...);

#endif
