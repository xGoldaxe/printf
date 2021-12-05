/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_merge.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 12:32:38 by pleveque          #+#    #+#             */
/*   Updated: 2021/12/05 13:19:58 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_realloc_merge(char **store, int nb_str, ...)
{
	char			*res;
	va_list			marker;
	int				i;
	int				res_size;

	va_start(marker, nb_str);
	res = NULL;
	res_size = 0;
	i = 0;
	while (i < nb_str)
	{
		res_size = ft_realloc_l_cat(va_arg(marker, char *),
				va_arg(marker, int), &res, res_size);
		if (res_size == -1)
		{
			free(res);
			res = NULL;
			return (-1);
		}
		i++;
	}
	if (*store)
		free(*store);
	*store = res;
	return (res_size);
}
