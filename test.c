/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 19:32:15 by ykliek            #+#    #+#             */
/*   Updated: 2019/01/10 19:32:16 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

int main(int argc, const char * argv[])
{
	char *str;

	str = (char *)malloc(7);
	str = "qwrqret";
	while (str)
	{
		if(*str >= 97 && *str <= 122)
			*str = *str - 32;
		str++;
	}	
   printf("%s\n", str);
}
