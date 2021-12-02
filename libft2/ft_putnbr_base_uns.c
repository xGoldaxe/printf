/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_uns.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:39:03 by pleveque          #+#    #+#             */
/*   Updated: 2021/12/02 19:10:55 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base_uns(unsigned int nbr, char *base, int *iteration)
{	
	unsigned int	modulo;
	unsigned int	division;
	unsigned int	base_size;

	*iteration += 1;
	base_size = ft_strlen(base);
	division = nbr / base_size;
	modulo = nbr % base_size;
	if (division != 0)
		ft_putnbr_base_uns(division, base, iteration);
	write(1, &base[modulo], 1);
}
