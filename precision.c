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
			while(str[start] >= 49 && str[start] <= 57)
				str1[count++] = str[start++];
			str1[count] = '\0';
			if (str[end] == 'f')
				str2 = precision_f(ft_atoi(str1), str2);
			else
				str2 = precision_diouxX(ft_atoi(str1), str2);
		}
		start++;
	}
	printf("%s\n", str2);
	return (str2);
}

char	*precision_diouxX(int num, char *str)
{
	int		count;
	int		count2;
	char	*str1;

	count = 0;
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

char	*precision_f(int num, char *str)
{
	int		count;
	int		count2;
	int 	length;
	char	*str1;

	count2 = 0;
	length = 0;
	while (str[length] != '.')
		length++;
	if ((int)ft_strlen(str) - length < num)
	{
		count = num - (ft_strlen(str) - length) + 1;
		str1 = (char *)malloc(count + 1);
		while (count2 != count)
			str1[count2++] = '0';
		str1[count2] = '\0';
		str1 = ft_strjoin(str, str1);
		return (str1);
	}
	return (str);
}