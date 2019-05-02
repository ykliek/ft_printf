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
	s_num		count;

	count.a = 0;
	count.b = -1;
	while (start <= end)
	{
		if (str[start - 1] == '.')
		{
			count.b = start;
			while (str[count.b] >= 48 && str[count.b] <= 57)
			{
				count.a++;
				count.b++;
			}
			str1 = (char *)malloc(count.a + 1);
			count.a = 0;
			while(str[start] >= 48 && str[start] <= 57)
				str1[count.a++] = str[start++];
			str1[count.a] = '\0';
			count.c = 1;
		}
		start++;
	}
	if (count.a != 0)
	    return (precision_diouxX(ft_atoi(str1), str2, str[end] , count));
	return (precision_diouxX(0, str2, str[end], count));
}

char	*precision_diouxX(int num, char *str, char c, s_num count1)
{
	int		count;
	int		count2;
	int		j;
	char	*str1;

	count2 = 0;
	j = (str[0] == '-') ? (int)ft_strlen(str) - 1 : (int)ft_strlen(str);
	if (c == 's' && count1.b != -1)
	{
		str1 = (char *)malloc(num + 1);
		while (count2 != num)
		{
			str1[count2] = str[count2];
			count2++;
		}
		str1[count2] = '\0';
		return (str1);
	}
	if (c != 's' && c != 'c')
		if (j < num)
		{
			count = num - j;
			str1 = (char *) malloc(count + 1);
			while (count2 != count)
				str1[count2++] = '0';
			str1[count2] = '\0';
			str1 = str_join_n(str1, str);
			return (str1);
		}
	if (num == 0 && str[0] == '0' && count1.c == 1)
		return(ft_strnew(1));
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