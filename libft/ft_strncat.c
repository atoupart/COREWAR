/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 10:42:24 by atoupart          #+#    #+#             */
/*   Updated: 2015/12/11 18:16:55 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s1[i] != 0)
		i++;
	while (s2[j] != 0 && n != 0)
	{
		s1[i] = s2[j];
		i++;
		j++;
		n--;
	}
	s1[i] = 0;
	return (s1);
}