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
//	ft_printf("MY_11111: @moulitest: %#.x %#.0x\n", 0, 0);
//	printf("PRINTF_1: @moulitest: %#.x %#.0x\n", 0, 0);
//	ft_printf("MY_22222: @moulitest: %.x %.0x\n", 0, 0);
//	printf("PRINTF_2: @moulitest: %.x %.0x\n", 0, 0);
//	ft_printf("MY_33333: @moulitest: %5.x %5.0x\n", 0, 0);
//	printf("PRINTF_3: @moulitest: %5.x %5.0x\n", 0, 0);
//	ft_printf("\t\t^WTF^\n");
//	ft_printf("\t===================\n");
	ft_printf("MY_44444: %0+5d\n", 42);
	printf("PRINTF_5: %0+5d\n", 42);
	ft_printf("MY:%05d\n", -42);
	printf("PR:%05d\n\n", -42);
	return (0);
}
