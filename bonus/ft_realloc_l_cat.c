/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_l_cat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:29:20 by pleveque          #+#    #+#             */
/*   Updated: 2021/12/04 17:49:14 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_realloc_l_cat(char *src, int src_size, char **dst, int dst_size)
{
	char	*tmp;
	int		i;
	int		y;

	tmp = malloc(sizeof(char) * (src_size + dst_size));
	if (!tmp)
		return (-1);
	i = 0;
	y = 0;
	while (i < dst_size)
	{
		tmp[i] = dst[0][i];
		i++;
	}
	while (y < src_size)
	{
		tmp[i + y] = src[y];
		y++;
	}
	free(*dst);
	*dst = tmp;
	return (dst_size + src_size);
}
