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

char 		*conditions(char *str, int end, char *res)
{
	if (ft_strchr(str, '+'))
		if (ft_atoi(res) > 0 && str[end] == 'd')
			res = ft_strjoin("+", res);
	if (ft_strchr(str, '#'))
	{
		if (str[end] == 'x' || str[end] == 'X')
			res = ft_strjoin(TEG(str, end), res);
		if (str[end] == 'o')
			res = ft_strjoin("0", res);
	}
	return (res);
}

char		*make_weigth(char *str, int start, int end, char *res)
{
	char	*str1;
	char	*null;
	char	*zero;
	int 	i[2];

	i[0] = start;
	i[1] = end;
	str1 = ft_strnew(1);
	while (start++ != end)
		if (str[start] > 48 && str[start] <= 57 && str[start - 1] != '.')
			str1 = parse_char(str[start]);
	null = ft_strnew(ft_atoi(str1));
	zero = ft_strnew(ft_atoi(str1));
	start = 0;
	res = conditions(str, end, res);
	if (str1 != NULL && ft_strlen(str1) != 0)
	{
		while (start < DIFF(ft_atoi(str1), (int)ft_strlen(res)) - TEST(str))
			null[start++] = ' ';
		start = 0;
		while (start < DIFF(ft_atoi(str1), (int)ft_strlen(res)) - TEST(str))
			zero[start++] = '0';
	}
	// 0
	if (str_s(str, i[0], i[1], '-') == 1)
		res = ft_strjoin(res, null);
	else if (str_s(str, i[0], i[1], '0') == 1 && str_s(str, i[0], i[1], '.') == 0)
		res = ft_strjoin(zero, res);
	else
		res = ft_strjoin(null, res);
	// 2 leaks
	if (str_s(str, i[0], i[1], ' ') == 1 && str_s(str, i[0], i[1], '+') == 0)
		if (ft_atoi(res) > 0 && str[end] == 'd')
			res = ft_strjoin(" ", res);
	// 1 leak
	free(str1);
	free(null);
	free(zero);
	return (res);
}

int		str_s(char *str, int start, int end, char c)
{
	char	*ret;
	int		count;

	count = 0;
	ret = ft_strnew(end - start + 1);
	while (start < end)
		ret[count++] = str[start++];
	ret[count] = '\0';
	count = 0;
	while (ret[count] != c)
	{
		if (ret[count] == '\0')
		{
			free(ret);
			return (0);
		}
		count++;
	}
	free(ret);
	return (1);
}