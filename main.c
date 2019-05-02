/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 15:04:36 by ykliek            #+#    #+#             */
/*   Updated: 2019/01/11 15:04:36 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		main()
{
	// ft_printf("%ll#x", 9223372036854775807);
	// ft_putstr("\x1b[31m");
	ft_printf("%5d\n", 42);
	 system("leaks a.out");
	return (0);
}

// 15. FAIL ft_printf("%ll#x", 9223372036854775807);      -> "0x7fffffffffffffff"
// 24. FAIL ft_printf("%50+d", 42);                        -> "  +42"
// 26. FAIL ft_printf("%-5+d", 42);                       -> "+42  "
// 30. FAIL ft_printf("%zhd", 4294967296);                -> "4294967296"
// 31. FAIL ft_printf("%jzd", 9223372036854775807);       -> "9223372036854775807"
// 32. FAIL ft_printf("%jhd", 9223372036854775807);       -> "9223372036854775807"
// 34. FAIL ft_printf("%lhlz", 9223372036854775807);      -> ""
// 35. FAIL ft_printf("%zj", 9223372036854775807);        -> ""
// 37. FAIL ft_printf("%hhld", 128);                      -> "128"
// 40. FAIL ft_printf("@main_ftprintf: %###-#0000 33...12..#0+0d", 256); -> "@main_ftprintf: +256  