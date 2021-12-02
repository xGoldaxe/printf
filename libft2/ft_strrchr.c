/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:22:08 by pleveque          #+#    #+#             */
/*   Updated: 2021/11/26 20:21:49 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*str;
	unsigned char	cc;

	cc = (unsigned char) c;
	str = (char *)s;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (str[i] == cc)
			return (str += i);
		i--;
	}
	if (*str == cc)
		return (str);
	return (0);
}
