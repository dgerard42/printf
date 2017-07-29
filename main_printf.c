/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 11:34:03 by dgerard           #+#    #+#             */
/*   Updated: 2017/07/21 15:11:07 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int			main(void)
{
//	int my_ret = 0;
//	int	real_ret = 0;
//printf("real_ret%d, my_ret%d\n", real_ret, my_ret);
	//CHAR TESTS ----------------------------
//	printf("%c\n", '*');
//	printf("%-42c\n", '*');
//	printf("%2c\n", '*');
//	printf("%-c\n", '*');

//	ft_printf("%c\n", '*');
//	ft_printf("%-42c\n", '*');
//	ft_printf("%2c\n", '*');
//	ft_printf("%-c\n", '*');
	//INT TESTS -----------------------------
	// printf("1.r.%d\n", 42);
	// printf("2.r.%d\n", -42);
	// printf("3.r.%+d\n", 0);
	// printf("4.r.%+d\n", -42);
	// printf("5.r.% d\n", 42);
	// printf("6.r.% d\n", -42);
	// printf("7.r.%-8d\n", 42);
	// printf("8.r.%8d\n", 42);
	// printf("9.r.%-d\n", 42);
	// printf("A.r.%08d\n", 42);
	// printf("B.r.%.0d\n", 42000);
	// printf("C.r.%.d\n", 42000);
	// printf("D.r.%.2d\n", 42000);
	// printf("E.r.%.10d\n", 42000);

	// ft_printf("1.m.%d\n", 42);
	// ft_printf("2.m.%d\n", -42);
	// ft_printf("3.m.%+d\n", 0);
	// ft_printf("4.m.%+d\n", -42);
	// ft_printf("5.m.% d\n", 42);
	// ft_printf("6.m.% d\n", -42);
	// ft_printf("7.m.%-8d\n", 42);
	// ft_printf("8.m.%8d\n", 42);
	// ft_printf("9.m.%-d\n", 42);
	// ft_printf("A.m.%08d\n", 42);
	// ft_printf("B.m.%.0d\n", 42000);
	// ft_printf("C.m.%.d\n", 42000);
	// ft_printf("D.m.%.2d\n", 42000);
	// ft_printf("E.m.%.10d\n", 42000);
	//INT LENGTH TESTS ----------------------
	char a = '*';
	short b = 42;
	long c = 42.000;
	long long d = 42.000000;
	size_t e = 42;
	intmax_t f = 42;

	printf("%hhd\n", a);
	printf("%hd\n", b);
	printf("%ld\n", c);
	printf("%lld\n", d);
	printf("%jd\n", e);
	printf("%zd\n", f);
	printf("%hld\n", c);

	// ft_printf("%hhd\n", a);
	// ft_printf("%hd\n", b);
	// ft_printf("%ld\n", c);
	// ft_printf("%lld\n", d);
	// ft_printf("%jd\n", e);
	// ft_printf("%zd\n", f);
	// ft_printf("%hld\n", c);
	//INTEGRATED STRING TESTS
	//STRING TESTS
	//HEX TESTS
	//POINTER TESTS
	//UNSIGNED INT TESTS
	//OCTALS TESTS
}

/*
int				main(void)
{
	//INITIAL TESTS
//	printf("%%\n");
//	ft_printf("%%\n");
//	printf("whats up bitches\n");
//	ft_printf("whats up bitches\n");
//	printf("%s\n\t%s", "yo", "42");
//	ft_printf("%s\n\t", "yo");
//	printf("shit here%dAND here!!\n", 42);
//	ft_printf("shit here%dAND here!!\n", 42);
}
*/
