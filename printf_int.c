/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:45:05 by pleveque          #+#    #+#             */
/*   Updated: 2021/12/02 18:53:09 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_int(va_list argptr)
{
	int	integer;

	integer = va_arg(argptr, int);
	return (ft_putnbr_fd(integer, 1));
}
