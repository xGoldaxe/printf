/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:41:55 by pleveque          #+#    #+#             */
/*   Updated: 2021/11/26 18:10:28 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*f;
	size_t			i;

	f = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (f[i] == (unsigned char)c)
			return ((unsigned char *)s + i);
		i++;
	}
	return (NULL);
}
