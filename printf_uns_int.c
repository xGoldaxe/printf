/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_uns_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:45:05 by pleveque          #+#    #+#             */
/*   Updated: 2021/12/02 19:07:39 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_uns_int(va_list argptr)
{
	unsigned int	u;

	u = va_arg(argptr, unsigned int);
	return (ft_putnbr_uns_fd(u, 1));
}
