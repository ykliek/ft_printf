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

# include <stdio.h> // delete before validation
# include <stdarg.h>
# include "./libft/libft.h"

int		ft_printf(const char *format, ...);

char	*parse_char(char c);

char	*address(long long int a);

char	*ft_itoa_base(int value, int base, char type);

char 	*str_toupper(char *str);

char 	*precision(int	start, int end, char *str, char *str2);

void		test(int count, char *str, va_list argptr);

char	*precision_diouxX(int num, char *str);

char		*find_type(char type, va_list argptr, int tol);

int		precision_f(int	start, int end, char *str);

char	*ft_ftoa(double n, int tol, int count);

#endif
