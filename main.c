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
	int b;

	b = 234;

	ft_printf("%.20f\n", 584.234);
	printf("%.20f\n", 584.234);
//	printf("%.20f\n", 584.287);
	//printf("%.1f\n", 12335765114522151656444444444.4);
	//printf("%s\n", ft_ftoa2(-12.345, 5, 0));
	//printf("%-6d\n", 24);
	//printf("%s\n", ft_ftoa(-12.2254, 7, 0));
	return (0);
}
