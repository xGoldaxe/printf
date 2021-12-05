/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 22:36:22 by pleveque          #+#    #+#             */
/*   Updated: 2021/11/27 13:43:45 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_include(char c, char const *elts)
{
	unsigned int	i;

	i = 0;
	while (elts[i])
	{
		if (elts[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_build_strtrim(char const *s1, char const *set,
unsigned int i, unsigned int y)
{
	char			*dst;
	unsigned int	len;

	if (!s1 || !set)
		return (NULL);
	while (s1[i] && ft_include(s1[i], set))
		i++;
	while (y < ft_strlen(s1) && ft_include(s1[ft_strlen(s1) - y - 1], set))
		y++;
	if (i == ft_strlen(s1))
		y = 0;
	len = ft_strlen(s1) - y - i;
	dst = malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	y = 0;
	while (y < len)
	{
		dst[y] = s1[i + y];
		y++;
	}
	dst[len] = '\0';
	return (dst);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	y;

	i = 0;
	y = 0;
	return (ft_build_strtrim(s1, set, i, y));
}
