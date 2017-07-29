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
	//CHAR TESTS
//	printf("%c\n", '*');
//	printf("%-42c\n", '*');
//	printf("%2c\n", '*');
//	printf("%-c\n", '*');
//	ft_printf("%c\n", '*');
//	ft_printf("%-42c\n", '*');
//	ft_printf("%2c\n", '*');
//	ft_printf("%-c\n", '*');
	//INT TESTS
	printf("%d\n", 42);
	printf("%d\n", -42);
	printf("%+d\n", 0);
	printf("%+d\n", -42);
	printf("% d\n", 42);
	printf("% d\n", -42);
	printf("%-8d\n", 42);
	printf("%8d\n", 42);
	printf("%-d\n", 42);
	printf("%08d\n", 42);
	printf("%.0d\n", 42000);
	printf("%.d\n", 42000);
	printf("%.2d\n", 42000);
	printf("%.10d\n", 42000);

	ft_printf("%d\n", 42);
	ft_printf("%d\n", -42);
	ft_printf("%+d\n", 0);
	ft_printf("%+d\n", -42);
	ft_printf("% d\n", 42);
	ft_printf("% d\n", -42);
	ft_printf("%-8d\n", 42);
	ft_printf("%8d\n", 42);
	ft_printf("%-d\n", 42);
	ft_printf("%08d\n", 42);
	ft_printf("%.0d\n", 42000);
	ft_printf("%.d\n", 42000);
	ft_printf("%.2d\n", 42000);
	ft_printf("%.10d\n", 42000);
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
