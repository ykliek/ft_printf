/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 20:04:19 by ykliek            #+#    #+#             */
/*   Updated: 2019/01/15 20:04:20 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		make_int(double n)
{
	int count;

	count = 0;
	while (count++ != 6)
		n = n * 10;
	count = n;
	return (count);
}

char	*make_str(char *str, int count, int count2, int n)
{
	str[count] = '\0';
	while (count--)
	{
		if (count + 7 == count2)
		{
			str[count] = '.';
			count--;
		}
		if (n < 0)
		{
			str[count] = '0' - (n % 10);
			if (n >= -9)
				str[0] = '-';
		}
		else
			str[count] = '0' + (n % 10);
		if (n / 10 != 0)
			n = n / 10;
	}
	return (str);
}

char			*ft_ftoa(double num)
{
	char	*str;
	int		count;
	int		count2;
	int		n;
	int		tmp;

	n = make_int(num);
	tmp = make_int(num);
	count = (n >= 0) ? 1 : 2;
	while (tmp /= 10)
		count++;
	count++;
	count2 = count;
	if ((str = (char *)malloc(count + 1)) == NULL)
		return (NULL);
	str = make_str(str, count, count2, n);
	return (str);
}

