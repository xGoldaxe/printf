/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_percentage.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:45:05 by pleveque          #+#    #+#             */
/*   Updated: 2021/12/02 17:28:04 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_percentage(const char src)
{
	if (src == '%')
		write(1, &src, 1);
	return (1);
}
