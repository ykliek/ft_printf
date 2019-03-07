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
	return ((i == 0) ? 1 : i);
}

char	*ft_ftoa(long double n, int tol, int count)
{
	char		*str;
	char		t;
	long double	tmp;

	tmp = n;
	if (n < 0)
	{
		str = ft_strnew(tol + 2);
		n = -n;
		str[count++] = '-';
	}
	else
	    str = ft_strnew(tol + find_count(n) + 1);
	str = ft_strjoin(ft_itoa((int)n), str);
	n = n - (int)n;
	count = count + find_count(tmp);
	n = n * 10;
	str[count++] = '.';
	while (tol-- > 0)
	{
		t = '0' + (int)n;
		str[count++] = t;
		n = n - (double)(t - '0');
		n *= 10;
	}
	str[count] = '\0';
	return (str);
}
