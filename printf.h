/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 19:55:14 by ykliek            #+#    #+#             */
/*   Updated: 2019/05/02 12:34:50 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# define DIFF(x, y) ((x > y) ? x - y : 0)
# define TEST(str, s, e) ((str_s(str, s, e, ' ') == 1 && str_s(str, s, e, '+')) != 1 ? 1 : 0)
# define TEG(str, end) ((str[end] == 'x') ? "0x" : "0X")
# define CHECKM(a) ((a < 0) ? 4294967296 : 0)

# include <stdio.h> // delete before pushing
# include <stdarg.h>
# include "./libft/libft.h"
#include <string.h>

# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"
# define WHITE "\x1b[37m"
# define B_RED "\x1b[31;1m"
# define B_GREEN "\x1b[32;1m"
# define B_YELLOW "\x1b[33;1m"
# define B_BLUE "\x1b[34;1m"
# define B_MAGENTA "\x1b[35;1m"
# define B_CYAN "\x1b[36;1m"
# define B_WHITE "\x1b[37;1m"
# define EOC "\x1b[0m"

typedef struct 	retValue
{
	int a;
	int b;
}				s_retValue;

typedef struct	s_tmp
{
	char *tmp1;
	char *tmp2;
	char *tmp3;
}				t_tmp;

typedef struct num
{
	int	a;
	int	b;
	int	c;
}				s_num;

int		ft_printf(const char *format, ...);

char	*parse_char(char c);

char	*address(long long int a);

char	*ft_itoa_base(long long int value, int base, char type);

char 	*str_toupper(char *str);

char 	*precision(int	start, int end, char *str, char *str2);

char	*precision_diouxX(int num, char *str, char c, s_num count1);

char	*find_type(char type, va_list argptr, int tol);

int		precision_f(int	start, int end, char *str);

char	*ft_ftoa(long double n, int tol, int count);

char	*modifiers(int start, int end, char *str, va_list argptr);

char	*make_weigth(char *str, int start, int end, char *res);

int		str_s(char *str, int start, int end, char c);

char	*str_join_n(char *s1, char *s2);

void	clear_tmp(t_tmp *tmp);

t_tmp		init(void);

// test

// char	*make_flags(char *str, int start, int end, char *res);

// not test

#endif
