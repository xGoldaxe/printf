/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 14:02:43 by pleveque          #+#    #+#             */
/*   Updated: 2021/12/05 14:02:51 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*ft_strfill(int size, char c)
{
	char	*filled;
	int		i;

	filled = malloc(sizeof(char) * size + 1);
	if (!filled)
		return (NULL);
	i = 0;
	while (i < size)
	{
		filled[i] = c;
		i++;
	}
	filled[i] = '\0';
	return (filled);
}
