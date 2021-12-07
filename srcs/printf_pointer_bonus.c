/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_pointer_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:45:05 by pleveque          #+#    #+#             */
/*   Updated: 2021/12/05 18:45:15 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*printf_pointer(unsigned long long arg)
{
	char				*res;
	char				*itoa;

	res = NULL;
	res = ft_realloc_cat("0x", NULL);
	itoa = ft_itoa_base_uns(arg, "0123456789abcdef");
	res = ft_realloc_cat(itoa, res);
	free(itoa);
	return (res);
}
