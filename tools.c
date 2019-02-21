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

char		*make_weigth(char *str, int start, int end, char *res)
{
    char    *str1;
    char    *null;
    char    flags[6];
    int     tmp;

    tmp = start;
    flags == "-+ #0";
	while (start != end)
    {
	    if (str[start] > 48 && str[start] <= 57 && str[start - 1] != '.')
	        str1 = parse_char(str[start]);
	    start++;
    }
    if (str1 == NULL)
        return (res);
	null = ft_strnew(ft_atoi(str1));
	start = 0;
	while (start != ft_atoi(str1))
	    null[start] = ' ';
	res = ft_strjoin(res, null);
	if (ft_strchr(flags, str[tmp])
            
	return (res);
}
