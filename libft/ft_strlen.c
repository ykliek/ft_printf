/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 13:44:06 by ykliek            #+#    #+#             */
/*   Updated: 2018/10/26 13:44:08 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int count;

	count = 0;
	if (s)
	{
		while (s[count] != '\0')
			count++;
		return (count);
	}
	return (NULL);
}
