/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:39:07 by ykliek            #+#    #+#             */
/*   Updated: 2019/02/19 15:55:06 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char		*make_weigth(char *str, int start, int end, char *res)
{
	char	*str1;
	char	*null;
	char	*zero;
	int		tmp;

	tmp = start;
	flag = ft_strnew(1);
	while (start != end)
	{
		if (str[start] > 48 && str[start] <= 57 && str[start - 1] != '.')
			str1 = parse_char(str[start]);
		start++;
	}
	if (str1 == NULL)
		return (res);
	null = ft_strnew(ft_atoi(str1));
	zero = ft_strnew(ft_atoi(str1));
	start = 0;
	while (start != ft_atoi(str1))
		null[start] = ' ';
	while (start != ft_atoi(str1))
		zero[start] = '0';
	if (ft_strchr(str, '+') != NULL)
		if (ft_atoi(res) > 0 && str[end] == 'd')
			res = ft_strjoin(res, '+');
	else if (ft_strchr(str, ' '))
		if (ft_atoi(res) > 0 && str[end] == 'd')
			res = ft_strjoin(res, ' ');
	if (ft_strchr(str, '-') != NULL)
		res = ft_strjoin(null, res);
	else if (ft_strchr(str, '0'))
		res = ft_strjoin(zero, res);
	else
		res = ft_strjoin(res, null);
}

char 		*make_flags(char *res, char *flag)
{

	return (res);
}
