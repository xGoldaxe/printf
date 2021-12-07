/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_trunc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:26:05 by pleveque          #+#    #+#             */
/*   Updated: 2021/12/06 14:41:51 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*ft_realloc_trunc(char *src, int len)
{
	char			*tmp;
	int				i;

	tmp = malloc(sizeof(char) * len);
	if (!tmp)
		return (NULL);
	i = 0;
	if (src)
	{
		while (src[i] && i < len)
		{
			tmp[i] = src[i];
			i++;
		}
		free(src);
	}
	tmp[i] = '\0';
	return (tmp);
}
