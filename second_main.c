/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 21:02:46 by dgerard           #+#    #+#             */
/*   Updated: 2017/08/12 21:02:48 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					main(void)
{
	//POINTER TESTS -------------------------------
	// int	*ugh;

	// printf("0.r.%p\n", 0);
	// printf("1.r.%p\n", ugh);
	// printf("2.r.%9.2p\n", 1234);
	//
	// ft_printf("0.m.%p\n", 0);
	// ft_printf("1.m.%p\n", ugh);
	// ft_printf("2.m.%9.2p\n", 1234);
	//MOULINETTE PRESCION ------------------------
	// printf("0.r.%-5.3s\n", "LYDIE");
	// printf("1.r.% 4.5i\n", 42);
	// printf("2.r.%04.5i\n", 42);
	// printf("3.r.%04.3i\n", 42);
	// printf("4.r.%04.2i\n", 42);

	// ft_printf("0.m.%-5.3s\n", "LYDIE");
	// ft_printf("1.m.% 4.5i\n", 42);
	// ft_printf("2.m.%04.5i\n", 42);
	// ft_printf("3.m.%04.3i\n", 42);
	// ft_printf("4.m.%04.2i\n", 42);
	//TERRY'S TEST --------------------------------
	// printf("%5%\n");

	// ft_printf("%5%\n");
	//LONG WIDTH TESTS ----------------------------
	printf("0.r.%ld\n", 2147483648);
	printf("1.r.%lD\n", 2147483648);
	printf("2.r.%D\n", 2147483648);
	printf("3.r.%ld\n", 4294959296);

	ft_printf("0.m.%ld\n", 2147483648);
	ft_printf("1.m.%lD\n", 2147483648);
	ft_printf("2.m.%D\n", 2147483648);
	ft_printf("3.m.%ld\n", 4294959296);
}
