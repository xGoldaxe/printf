/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strldup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 13:34:34 by pleveque          #+#    #+#             */
/*   Updated: 2021/12/05 13:39:01 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*ft_strldup(const char *s, int size)
{
	char	*newstr;

	newstr = malloc(sizeof(char) * size + 1);
	if (newstr == NULL)
		return (NULL);
	ft_strlcpy(newstr, s, size + 1);
	return (newstr);
}
