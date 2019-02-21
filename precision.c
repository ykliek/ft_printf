/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 12:49:15 by ykliek            #+#    #+#             */
/*   Updated: 2019/01/16 12:49:19 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char 	*precision(int	start, int end, char *str, char *str2)
{
	char 	*str1;
	int		count;
	int		tmp;

	count = 0;
	while (start <= end)
	{
		if (str[start - 1] == '.')
		{
			tmp = start;
			while (str[tmp] >= 48 && str[tmp] <= 57)
			{
				count++;
				tmp++;
			}
			str1 = (char *)malloc(count + 1);
			count = 0;
			while(str[start] >= 48 && str[start] <= 57)
				str1[count++] = str[start++];
			str1[count] = '\0';
		}
		start++;
	}
	if (count != 0)
	    return (precision_diouxX(ft_atoi(str1), str2));
	return (precision_diouxX(0, str2));
}

char	*precision_diouxX(int num, char *str)
{
	int		count;
	int		count2;
	char	*str1;

	count2 = 0;
	if ((int)ft_strlen(str) < num)
	{
		count = num - ft_strlen(str);
		str1 = (char *)malloc(count + 1);
		while (count2 != count)
			str1[count2++] = '0';
		str1[count2] = '\0';
		str1 = ft_strjoin(str1, str);
		return (str1);
	}
	return (str);
}

int		precision_f(int	start, int end, char *str)
{
	char 	*str1;
	int		tmp;
	int		count;

	count = 0;
	while (start <= end)
	{
		if (str[start - 1] == '.')
		{
			tmp = start;
			while (str[tmp] >= 48 && str[tmp] <= 57)
			{
				count++;
				tmp++;
			}
			str1 = (char *)malloc(count + 1);
			count = 0;
			while(str[start] >= 48 && str[start] <= 57)
				str1[count++] = str[start++];
			str1[count] = '\0';
			return (ft_atoi(str1));
		}
		start++;
	}
	return (6);
}