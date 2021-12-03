/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:50:09 by pleveque          #+#    #+#             */
/*   Updated: 2021/11/26 19:28:25 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	char	*res;

	res = (char *)haystack;
	if (!*needle)
		return (res);
	i = 0;
	while (i < len && haystack[i])
	{
		if (haystack[i] == *needle)
		{
			if ((i + ft_strlen(needle)) <= len)
			{
				if (ft_strncmp(&haystack[i], needle, ft_strlen(needle)) == 0)
					return (res += i);
			}
		}
		i++;
	}
	return (NULL);
}
