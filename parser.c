/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 17:34:13 by ykliek            #+#    #+#             */
/*   Updated: 2019/01/11 17:34:15 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*address(long long int a)
{
	unsigned int p;
	char	*s;
	int		i;

	p = (unsigned int)a;
	s = (char *)malloc(2 * sizeof(p));
	i = 2 * sizeof(p) - 1;
	while (i >= 0)
	{
		s[i] = "0123456789abcdef"[p & 0x0F];
		p >>= 4;
		i--;
	}
	s[i] = '\0';
	s = ft_strjoin("0x7ffe", s);
	return (s);
}

char	*parse_char(char c)
{
	char *str;

	if (c)
	{
		str = ft_strnew(2);
		str[0] = c;
		str[1] = '\0';
		return (str);
	}
	return (ft_strdup("^@"));
}

char 	*str_toupper(char *str)
{
	int		count;

	count = 0;
	while (str[count] != '\0')
	{
		if (str[count] >= 97 && str[count] <= 122)
			str[count] = str[count] - 32;
		count++;
	}
	return (str);
}

char	*str_join_n(char *s1, char *s2)
{
	char	*str;
	int		count;
	int		count_1;

	count = 0;
	count_1 = 0;
	if (s1 && s2)
	{
		str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (!str)
			return (NULL);
		if (s2[0] == '-' || s2[0] == '+')
			str[count_1] = (s2[0] == '-') ? '-' : '+';
		count_1++;
		while (s1[count] != '\0')
			str[count_1++] = s1[count++];
		count = (s2[0] == '-' || s2[0] == '+') ? 1 : 0;
		while (s2[count] != '\0')
			str[count_1++] = s2[count++];
		str[count_1] = '\0';
		return (str);
	}
	return (NULL);
}
