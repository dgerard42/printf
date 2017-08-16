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
	//HARD TESTS --------------------------------
	// printf("%5%\n");
	// printf("r.%015u\n", 4294967295);
	// printf("r.0.{%10R}\n");
	// printf("r.1.{%-15Z}\n", 123);
	// printf("r.2.% Zoooo\n");
	// printf("r.3.{%}\n");
	printf("r.4.{% S}\n", L"(null)");

	// ft_printf("%5%\n");
	// ft_printf("m.%015u\n", 4294967295);
	// ft_printf("m.0.{%10R}\n");
	// ft_printf("m.1.{%-15Z}\n", 123);
	// ft_printf("m.2.% Zoooo\n");
	// ft_printf("m.3.{%}\n");
	ft_printf("m.4.{% S}\n", L"(null)");
	//LONG WIDTH TESTS ----------------------------
	// printf("0.r.%ld\n", 2147483648);
	// printf("1.r.%lD\n", 2147483648);
	// printf("2.r.%D\n", 2147483648);
	// printf("3.r.%ld\n", 4294959296);
	//
	// ft_printf("0.m.%ld\n", 2147483648);
	// ft_printf("1.m.%lD\n", 2147483648);
	// ft_printf("2.m.%D\n", 2147483648);
	// ft_printf("3.m.%ld\n", 4294959296);
	//FLAGS MIXED WITH PRESICION -------------------
	//are these undefined behaviors?
	//undefined!! printf("{%05.S}\n", L"42 c est cool");
	//undefined!! printf("{%05.s}\n", 0);
	//undefined!! printf("{%05.c}\n", 0);
	printf("r.5.{%05.Z}\n", 0);
	printf("r.6.{%05.%}\n", 0);
	printf("r.7.%#.3o\n", 1);

	ft_printf("m.5.{%05.Z}\n", 0);
	ft_printf("m.6.{%05.%}\n", 0);
	ft_printf("m.7.%#.3o\n", 1);
	//min width flag 0 -------------------------------
	// undefined!! printf("{%05s}\n", "abc");
	// undefined!! printf("{%03c}\n", 0);
}
