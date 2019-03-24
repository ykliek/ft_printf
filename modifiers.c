/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 12:37:51 by ykliek            #+#    #+#             */
/*   Updated: 2019/02/06 12:37:52 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char    *make_mode_dio(char *str, va_list argptr, char type, int tol)
{
	char    *res;

	res = ft_strnew(1);
	if (str == NULL)
		res = find_type(type, argptr, tol);
	else if ((type == 'd' && ft_strcmp(str, "hh") == 0) || (type == 'i' && ft_strcmp(str, "hh") == 0))
		res = ft_itoa(va_arg(argptr, int));
    else if((type == 'd' && ft_strcmp(str, "h") == 0) || (type == 'i' && ft_strcmp(str, "h") == 0))
		res = ft_itoa(va_arg(argptr, unsigned int));
    else if ((type == 'd' && ft_strcmp(str, "l") == 0) || (type == 'i' && ft_strcmp(str, "l") == 0))
		res = ft_itoa(va_arg(argptr, unsigned long int));
    else if ((type == 'd' && ft_strcmp(str, "ll") == 0) || (type == 'i' && ft_strcmp(str, "ll") == 0))
		res = ft_itoa(va_arg(argptr, unsigned long long int));
	else if (type == 'o' && ft_strcmp(str, "hh") == 0)
		res = ft_itoa_base(va_arg(argptr, int), 8, type);
	else if (type == 'o' && ft_strcmp(str, "h"))
		res = ft_itoa_base(va_arg(argptr, unsigned int), 8, type);
	else if (type == 'o' && ft_strcmp(str, "l") == 0)
		res = ft_itoa_base(va_arg(argptr, unsigned long int), 8, type);
	else
		res = ft_itoa_base(va_arg(argptr, unsigned long long int), 8, type);
	return (res);
}

char    *make_mode_uxXf(char *str, va_list argptr, char type, int tol)
{
	char    *res;

	res = ft_strnew(1);
	if (str == NULL)
		res = find_type(type, argptr, tol);
    else if ((type == 'x' && ft_strcmp(str, "hh") == 0) || (type == 'X' && ft_strcmp(str, "hh") == 0))
		res = ft_itoa_base(va_arg(argptr, int), 16, type);
    else if ((type == 'x' && ft_strcmp(str, "h") == 0) || (type == 'X' && ft_strcmp(str, "h") == 0))
		res = ft_itoa_base(va_arg(argptr, unsigned int), 16, type);
    else if ((type == 'x' && ft_strcmp(str, "l") == 0) || (type == 'X' && ft_strcmp(str, "l") == 0))
		res = ft_itoa_base(va_arg(argptr, unsigned long int), 16, type);
    else if ((type == 'x' && ft_strcmp(str, "ll") == 0) || (type == 'X' && ft_strcmp(str, "ll") == 0))
		res = ft_itoa_base(va_arg(argptr, unsigned long long int), 16, type);
	else
		res = ft_ftoa(va_arg(argptr, long double), tol, 0);
	return (res);
}

char        *modifiers(int start, int end, char *str, va_list argptr)
{
	char    *res;
	char    str1[3];
	int     count;

	res = ft_strnew(1);
	count = 0;
	while(str[start] != str[end])
	{
		if (str[start] == 'l' || str[start] == 'h' || str[start] == 'L')
			str1[count++] = str[start++];
		else
			start++;
	}
	str1[count] = '\0';
	if (str[end] == 'd' || str[end] == 'i' || str[end] == 'o')
		res = make_mode_dio(str1, argptr, str[end], precision_f(start, end, str));
	else
		res = make_mode_uxXf(str1, argptr, str[end], precision_f(start, end, str));
	return (res);
}

