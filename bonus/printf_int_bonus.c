/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_int_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:45:05 by pleveque          #+#    #+#             */
/*   Updated: 2021/12/05 14:56:58 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*printf_int(char *content, int precision)
{
	char	*res;

	if (precision != -1)
	{
		precision -= ft_strlen(content);
		res = ft_realloc_cat(content, ft_strfill(precision, '0'));
	}
	else
		return (content);
	free(content);
	return (res);
}
