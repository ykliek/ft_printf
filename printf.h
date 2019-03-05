/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 19:55:14 by ykliek            #+#    #+#             */
/*   Updated: 2019/01/10 19:55:15 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# define DIFF(x, y) ((x > y) ? x - y : 0)
# define TEST(str) ((ft_strchr(str, ' ') && !ft_strchr(str, '+')) ? 1 : 0)
# define TEG(str, end) ((str[end] == 'x') ? "0x" : "0X")
# define CHECKM(a) ((a < 0) ? 4294967296 : 0)

# include <stdio.h> // delete before pushing
# include <stdarg.h>
# include "./libft/libft.h"

int			ft_printf(const char *format, ...);

char	*parse_char(char c);

char	*address(long long int a);

char	*ft_itoa_base(int value, int base, char type);

char 	*str_toupper(char *str);

char 	*precision(int	start, int end, char *str, char *str2);

char	*precision_diouxX(int num, char *str);

char		*find_type(char type, va_list argptr, int tol);

int		precision_f(int	start, int end, char *str);

char	*ft_ftoa(long double n, int tol, int count);

char        *modifiers(int start, int end, char *str, va_list argptr);

char       *make_weigth(char *str, int start, int end, char *res);

#endif
