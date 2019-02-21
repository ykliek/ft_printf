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

int		print(int count, char *str, va_list argptr)
{
	char 	*str2;
	int		tmp;

	tmp = count;
	while (ft_strchr("cspfdiouxX", str[count]) == NULL)
		count++;
	if (str[count - 1] < 65 || str[count - 1] > 122)
		str2 = find_type(str[count], argptr, precision_f(tmp, count, str));
	else
		str2 = modifiers(tmp, count, str, argptr);
	if (str[count] != 'f')
		str2 = precision(tmp, count, str, str2);
	str2 = make_weigth(str,tmp, count, str2);
	ft_putstr(str2);
	return (count - tmp);
}

char		*find_type(char type, va_list argptr, int tol)
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
		str = ft_ftoa(va_arg(argptr, double), tol, 0);
	return (str);
}



int		ft_printf(const char *format, ...)
{
	int		count;
	int		end;
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
			end = print(count, (char *)format, argptr);
			count += end;
		}
		count++;
	}
	va_end(argptr);
	return (count);
}

