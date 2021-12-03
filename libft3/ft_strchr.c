/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:22:08 by pleveque          #+#    #+#             */
/*   Updated: 2021/11/26 20:18:56 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*str;
	unsigned char	cc;

	cc = (unsigned char) c;
	str = (unsigned char *)s;
	while (*str)
	{
		if (*str == cc)
			return ((char *) str);
		str++;
	}
	if (cc == '\0')
		return ((char *) str);
	return (0);
}
