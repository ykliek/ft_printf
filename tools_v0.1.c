/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_v0.1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:19:03 by ykliek            #+#    #+#             */
/*   Updated: 2019/04/09 18:19:05 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		find_width(char *str, int start, int end, char *res)
{
	int		i;
	char	*ret;
	int		num;

	i = 0;
	ret = ft_strnew(1);
	while (str[start] <= '0' || str[start] > '9')
	{
		if (start == end || str[start] == '.')
			break ;
		start++;
	}
	while (1)
	{
		if (str[start] >= '0' && str[start] <= '9')
			ret = ft_strjoin(ret, parse_char(str[start]));
		else
			break ;
		start++;
	}
	num = ft_atoi(ret) - ft_strlen(res);
	return ((num < 0) ? 0 : num);
}

int		flags(char *str, int start, int end, char c)
{
	while (str[start] <= '0' || str[start] > '9')
	{
		if (start == end || str[start] == '.')
			break ;
		if (str[start] == c)
			return (1);
		start++;
	}
	return (0);
}

char 	*make_str(char c, int length)
{
	char 	*str;
	int		count;

	count = 0;
	str = (char *)malloc(length + 1);
	while (count < length)
		str[count++] = c;
	str[count] = '\0';
	return (str);
}

char		*make_weigth(char *str, int start, int end, char *res)
{
	if (flags(str, start, end, '#') && ft_atoi(res) != 0)
	{
		if (str[end] == 'x' || str[end] == 'X')
			res = ft_strjoin(TEG(str, end), res);
		if (str[end] == 'o')
			res = ft_strjoin("0", res);
	}
	if (flags(str, start, end, '+'))
		if (ft_atoi(res) >= 0 && str[end] != 's' && str[end] != 'c'
			&& str[end] != '%')
			res = ft_strjoin("+", res);
	if (flags(str, start, end, ' ') == 1 && flags(str, start, end, '+') == 0)
		if (ft_atoi(res) > 0 && str[end] != 'c' && str[end] != 's'
			&& str[end] != '%')
			res = ft_strjoin(" ", res);
	if (flags(str, start, end, '-') != 1 && flags(str, start, end, '0') != 1)
		res = ft_strjoin(make_str(' ', find_width(str, start, end, res)), res);
	if (flags(str, start, end, '-') == 1 && flags(str, start, end, '0') != 1)
		res = ft_strjoin(res, make_str(' ', find_width(str, start, end, res)));
	if (flags(str, start, end, '0') == 1 && flags(str, start, end, '-') == 0)
		if (ft_strchr(ft_strsub(str, start, end), '.') == NULL
			&& ft_strchr("dioxX", str[end]) == NULL)
			res = str_join_n(make_str('0', find_width(str, start, end, res)), res);
	return (res);
}
