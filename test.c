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

int		find_count(double num)
{
	int		i;

	i = 0;
	num = (num < 0) ? -num : num;
	while ((int)num > 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

int main(int argc, const char * argv[])
{
	double t;


	t = 8;
	printf("%.100f", 123.34534);
}

