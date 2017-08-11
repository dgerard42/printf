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
	// int my_ret = 0;
	// int real_ret = 0;
	// printf("real_ret%d, my_ret%d\n", real_ret, my_ret);
	//CHAR TESTS ----------------------------
	// printf("1.r.%c\n", '*');
	// printf("2.r.%%%c\n", '*');
	// printf("3.r.%-8c\n", '*');
	// printf("4.r.%2c\n", '*');
	// printf("5.r.%-c\n", '*');
	//
	// ft_printf("1.m.%c\n", '*');
	// ft_printf("2.m.%%%c\n", '*');
	// ft_printf("3.m.%-8c\n", '*');
	// ft_printf("4.m.%2c\n", '*');
	// ft_printf("5.m.%-c\n", '*');
	//INT TESTS -----------------------------
	// *printf("i.r.0.%d\n", 2147483648);
	// printf("1.r.%d\n", 2147483648);
	// printf("2.r.%d\n", -2147483648);
	// printf("3.r.%+  d\n", 42);
	// printf("4.r.%0+5d\n", 42);
	// printf("5.r.% d\n", 42);
	// printf("6.r.% d\n", -42);
	// printf("7.r.%-8d\n", 42);
	// printf("8.r.%8d\n", 420);
	// printf("9.r.%-d\n", 42);
	// printf("A.r.%08d\n", 42);
	// printf("B.r.%.0d\n", 42000);
	// printf("C.r.%.d\n", 42000);
	// printf("D.r.%.2d\n", 8323);
	// printf("E.r.%.10d\n", 696969);
	// printf("F.r.%0d\n", 42);
	// printf("G.r.%d\n", 100);
	//

	// *ft_printf("i.m.0.%d\n", 2147483648);
	// ft_printf("1.m.%d\n", 2147483648);
	// ft_printf("2.m.%d\n", -2147483648);
	// ft_printf("3.m.%+  d\n", 42);
	// ft_printf("4.m.%0+5d\n", 42);
	// ft_printf("5.m.% d\n", 42);
	// ft_printf("6.m.% d\n", -42);
	// ft_printf("7.m.%-8d\n", 42);
	// ft_printf("8.m.%8d\n", 420);
	// ft_printf("9.m.%-d\n", 42);
	// ft_printf("A.m.%08d\n", 42);
	// ft_printf("B.m.%.0d\n", 42000);
	// ft_printf("C.m.%.d\n", 42000);
	// ft_printf("D.m.%.2d\n", 8323);
	// ft_printf("E.m.%.10d\n", 696969);
	// ft_printf("F.r.%0d\n", 42);
	// ft_printf("G.m.%d\n", 100);
	//INT LENGTH TESTS ----------------------
	// char a = '*';
	// short b = 42;
	// long c = 42.000;
	// long long d = 42.000000;
	// size_t e = 42;
	// intmax_t f = 42;
	//
	// printf("1.r.%hhd\n", a);
	// printf("2.r.%hd\n", b);
	// printf("3.r.%ld\n", c);
	// printf("4.r.%lld\n", d);
	// printf("5.r.%jd\n", e);
	// printf("6.r.%zd\n", f);
	// printf("l.7.r.%hld\n", c);
	// *printf("l.8.r.%hd\n", 32768);
	// *printf("l.9.r.%hhd\n", 128);
	// *printf("l.0.r.%hhd\n", -129);
	//
	// ft_printf("1.m.%hhd\n", a);
	// ft_printf("2.m.%hd\n", b);
	// ft_printf("3.m.%ld\n", c);
	// ft_printf("4.m.%lld\n", d);
	// ft_printf("5.m.%jd\n", e);
	// ft_printf("6.m.%zd\n", f);
	// ft_printf("l.7.m.%hld\n", c);
	// *ft_printf("l.8.m.%hd\n", 32768);
	// *ft_printf("l.9.m.%hhd\n", 128);
	// *ft_printf("l.0.m.%hhd\n", -129);
	//STRING TESTS -------------------------
	// char *string = "hella";

	// printf("r.1.%s\n", string);
	// printf("r.2.%s\n", "fug");
	// printf("r.3.%-2s\n", string);
	// printf("r.4.%-2s\n", "fug");
	// printf("r.5.%.2s\n", string);
	// printf("r.6.%.2s\n", "fug");
	// printf("r.7.%8s\n", string);
	// printf("r.8.%8s\n", "fug");
	// printf("r.9.%-10s\n", string);
	// printf("r.A.%-10s\n", "fug");
	// printf("%ls\n", string);
	// printf("%ls\n", "fug");

	// ft_printf("m.1.%s\n", string);
	// ft_printf("m.2.%s\n", "fug");
	// ft_printf("m.3.%-4s\n", string);
	// ft_printf("m.4.%-4s\n", "fug");
	// ft_printf("m.5.%.2s\n", string);
	// ft_printf("m.6.%.2s\n", "fug");
	// ft_printf("m.7.%8s\n", string);
	// ft_printf("m.8.%8s\n", "fug");
	// ft_printf("m.9.%-10s\n", string);
	// ft_printf("m.A.%-10s\n", "fug");
	// ft_printf("%ls\n", string);
	// ft_printf("%ls\n", "fug");
	//CHALLENGING PRESICION / WIDTH TESTS -------
	printf("r.1.%+d\n", 424242424242424242);
	printf("r.2.%0+5d\n", 42);
	printf("r.3.%5d\n", -42);
	printf("r.4.%05d\n", -42);
	printf("r.5.%0+5d\n", -42);
	printf("r.6.%-5d\n", -42);
	printf("r.7.%-05d\n", -42);
	printf("r.8.%4.15d\n", 42);
	printf("r.9.%.10d\n", 4242);
	printf("r.A.%10.5d\n", 4242);
	printf("r.B.%-10.5d\n", 4242);
	printf("r.C.% 10.5d\n", 4242);
	printf("r.D.%+10.5d\n", 4242);
	printf("r.E.%-+10.5d\n", 4242);
	printf("r.F.%03.2d\n", 0);
	printf("r.G.%03.2d\n", 1);
	printf("r.H.%03.2d\n", -1);

	ft_printf("m.1.%+d\n", 424242424242424242);
	ft_printf("m.2.%0+5d\n", 42);
	ft_printf("m.3.%5d\n", -42);
	ft_printf("m.4.%05d\n", -42);
	ft_printf("m.5.%0+5d\n", -42);
	ft_printf("m.6.%-5d\n", -42);
	ft_printf("m.7.%-05d\n", -42);
	ft_printf("m.8.%4.15d\n", 42);
	ft_printf("m.9.%.10d\n", 4242);
	ft_printf("m.A.%10.5d\n", 4242);
	ft_printf("m.B.%-10.5d\n", 4242);
	ft_printf("m.C.% 10.5d\n", 4242);
	ft_printf("m.D.%+10.5d\n", 4242);
	ft_printf("m.E.%-+10.5d\n", 4242);
	ft_printf("m.F.%03.2d\n", 0);
	ft_printf("m.G.%03.2d\n", 1);
	ft_printf("m.H.%03.2d\n", -1);
	//HEX TESTS --------------------------------
	// printf("1.r.%+x\n", 42);
	// printf("2.r.%x\n", -42);
	// printf("3.r.%jx\n", -4294967296);
	// ft_printf("1.m.%+x\n", 42);
	// ft_printf("2.m.%x\n", -42);
	// ft_printf("3.m.%jx\n", -4294967296);
	//UNSIGNED INT TESTS
	// printf("1.r.%+u\n", 42);
	// printf("2.r.%u\n", -42);
	// printf("3.r.%U\n", 4294967296);
	// ft_printf("1.m.%+u\n", 42);
	// ft_printf("2.m.%u\n", -42);
	// ft_printf("3.m.%U\n", 4294967296);
	//OCTALS TESTS
	// printf("1.r.%+o\n", 42);
	// printf("2.r.%o\n", -42);
	// printf("3.r.%o\n", 40);
	// printf("r.4.%#6o\n", 2500);
	// printf("r.5.%-#6o\n", 2500);
	// printf("r.6.%-05o\n", 2500);
	// printf("r.7.%-5.10o\n", 2500);
	// ft_printf("1.m.%+o\n", 42);
	// ft_printf("2.m.%o\n", -42);
	// ft_printf("3.m.%o\n", 40);
	// ft_printf("m.4.%#6o\n", 2500);
	// ft_printf("m.5.%-#6o\n", 2500);
	// ft_printf("m.6.%-05o\n", 2500);
	// ft_printf("m.7.%-5.10o\n", 2500);
	//POINTER TESTS
}
