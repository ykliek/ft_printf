/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 19:53:59 by ykliek            #+#    #+#             */
/*   Updated: 2019/01/11 20:13:26 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		test(int count, char *str, va_list argptr)
{
	char 	*str1;
	char 	*str2;
	int		tmp;

	tmp = count;
	str1 = ft_strnew(8);
	str1 = "cspfdiouxX";
	while (str[count] != '\0')
	{
		if (ft_strchr(str1, str[count]) != NULL)
		{
			str2 = find_type(str[count], argptr);
			precision(tmp, count, str, str2);
		}
		count++;
	}
}

char		*find_type(char type, va_list argptr)
{
	char	*str;

	if (type == 'd' || type == 'i')
		str = ft_itoa(va_arg(argptr, int));
	if (type == 'c')
		str = parse_char(va_arg(argptr, int));
	if (type == 's')
		str = va_arg(argptr, char *);
	if (type == 'p')
		str = address(va_arg(argptr, long long int));
	if (type == 'o')
		str = ft_itoa_base(va_arg(argptr, int), 8, type);
	if (type == 'x' || type == 'X')
		str = ft_itoa_base(va_arg(argptr, int), 16, type);
	if (type == 'f')
		str = ft_ftoa(va_arg(argptr, double));
	return (str);
}



int		ft_printf(const char *format, ...)
{
	int		count;
	va_list	argptr;

	count = 0;
	va_start(argptr, format);
	while (format[count] != '\0')
	{
		if (format[count + 1] == '%' && format[count] == '%')
		{
			ft_putchar('%');
			count = count + 2;
		}
		if (format[count] != '%')
			write(1, &format[count], 1);
		if (format[count] == '%')
		{
			test(count, (char *)format, argptr);
			count++;
		}
		count++;
	}
	va_end(argptr);
	return (count);
}

