/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:26:05 by pleveque          #+#    #+#             */
/*   Updated: 2021/12/06 14:41:44 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*ft_realloc_char(char c, char *dst)
{
	char			*tmp;
	size_t			len;

	len = ft_strlen(dst);
	tmp = malloc(sizeof(char) * (len + 2));
	if (!tmp)
		return (NULL);
	tmp[len] = c;
	if (dst)
	{
		free(dst);
		dst = NULL;
	}
	tmp[len + 1] = '\0';
	return (tmp);
}
