/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 13:04:56 by ykliek            #+#    #+#             */
/*   Updated: 2019/01/21 13:04:58 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*ft_ftoa(double n, int tol, int count)
{
	char	*str;
	char	t;
	int		i;

	i = tol + find_count(n);
	str = ft_strnew(i + 2);
	if (n < 0)
	{
		n = -n;
		str[count++] = '-';
	}
	while ((int)n > 0)
		n = n / 10;
	n = n * 10;
	while (i-- > 0)
	{
		t = '0' + (int)(n + 0.1);
		str[count++] = t;
		if (i == tol)
			str[count++] = '.';
		n = n - (double)(t - '0');
		n *= 10;
	}
	str[count] = '\0';
	return (str);
}
