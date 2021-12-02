/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:45:05 by pleveque          #+#    #+#             */
/*   Updated: 2021/12/02 19:10:00 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_hexa(va_list argptr, char *base)
{
	int				integer;
	unsigned int	uns;
	int				*i_ptr;
	int				iteration;

	integer = va_arg(argptr, int);
	uns = (unsigned int) integer;
	iteration = 0;
	i_ptr = &iteration;
	ft_putnbr_base_uns(uns, base, i_ptr);
	return (iteration);
}
