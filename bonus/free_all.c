/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:28:36 by pleveque          #+#    #+#             */
/*   Updated: 2021/12/06 14:24:48 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	*free_all(int nb_free, ...)
{
	char			*to_free;
	va_list			marker;
	int				i;

	va_start(marker, nb_free);
	i = 0;
	while (i < nb_free)
	{
		to_free = va_arg(marker, void *);
		free(to_free);
		i++;
	}
	return (NULL);
}
