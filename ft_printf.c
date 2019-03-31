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

s_retValue		print(int count, char *str, va_list argptr)
{
	char 	*str2;
	int		tmp;
	s_retValue ret;

	tmp = count;
	count++;
	while (ft_strchr("cspfdiouxX%", str[count]) == NULL)
		count++;
	if (str[count - 1] < 65 || str[count - 1] > 122)
		str2 = find_type(str[count], argptr, precision_f(tmp, count, str));
	else
		str2 = modifiers(tmp, count, str, argptr);
	if (str[count] != 'f')
		str2 = precision(tmp, count, str, str2);
	str2 = make_weigth(str, tmp, count, str2);
	ft_putstr(str2);
	ret.b = (int)ft_strlen(str2);
	free(str2);
	ret.a = count - tmp;
	return (ret);
}

char		*find_type(char type, va_list argptr, int tol)
{
	char	*str;
	int 	a;

	str = ft_strnew(1);
	if (type == 'u')
	{
		a = va_arg(argptr, unsigned int);
		str = ft_itoa(CHECKM(a) + a);
	}
	if (type == '%')
		str = ft_strjoin(str, "%");
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
	if (!str)
		return (ft_strdup("(null)"));
	return (str);
}



int		ft_printf(const char *format, ...)
{
	int			count;
	int			end;
	va_list		argptr;
	int			ret;
	s_retValue	num;

	count = 0;
	ret = 0;
	va_start(argptr, format);
	 while (format[count] != '\0')
	 {
	 	if (format[count] != '%')
		{
			write(1, &format[count], 1);
			ret++;
		}
	 	if (format[count] == '%')
	 	{
			num = print(count, (char *)format, argptr);
	 		end = num.a;
	 		ret = ret + num.b;
	 		count += end;
	 	}
	 	count++;
	 }
	va_end(argptr);
	return (ret);
}

