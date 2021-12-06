/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:39:03 by pleveque          #+#    #+#             */
/*   Updated: 2021/12/02 18:42:49 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putnbr_base(int nbr, char *base)
{	
	int	modulo;
	int	division;
	int	base_size;

	base_size = ft_strlen(base);
	division = nbr / base_size;
	modulo = nbr % base_size;
	if (division != 0)
		ft_putnbr_base(division, base);
	write(1, &base[modulo], 1);
}
