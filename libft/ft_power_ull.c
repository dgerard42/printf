/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power_ull.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 14:32:40 by dgerard           #+#    #+#             */
/*   Updated: 2017/08/06 16:58:35 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uintmax_t					ft_power_ull(uintmax_t nbr, uintmax_t power)
{
	uintmax_t tmp_nbr;

	tmp_nbr = nbr;
	while (power-- > 1)
		nbr *= tmp_nbr;
	return (nbr);
}
