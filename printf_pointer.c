/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:45:05 by pleveque          #+#    #+#             */
/*   Updated: 2021/12/02 19:14:20 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base_long(unsigned long long nbr, char *base, int *ptr_size);

int	printf_pointer(va_list argptr)
{
	unsigned long long	integer;
	int					*iteration_ptr;
	int					i;

	integer = va_arg(argptr, unsigned long long);
	if (!integer)
	{
		ft_putstr_fd("0x0", 1);
		return (3);
	}
	ft_putstr_fd("0x", 1);
	iteration_ptr = &i;
	i = 2;
	ft_putnbr_base_long(integer, "0123456789abcdef", iteration_ptr);
	return (i);
}

void	ft_putnbr_base_long(unsigned long long nbr, char *base, int *iteration)
{	
	unsigned long long	modulo;
	unsigned long long	division;
	unsigned long long	base_size;

	*iteration += 1;
	base_size = ft_strlen(base);
	division = nbr / base_size;
	modulo = nbr % base_size;
	if (division != 0)
		ft_putnbr_base_long(division, base, iteration);
	write(1, &base[modulo], 1);
}
