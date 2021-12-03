/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:31:39 by pleveque          #+#    #+#             */
/*   Updated: 2021/11/26 17:24:15 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dst;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	dst = ft_strdup(s);
	if (!dst)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dst[i] = (*f)(i, dst[i]);
		i++;
	}
	return (dst);
}
