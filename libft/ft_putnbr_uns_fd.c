/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uns_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:33:46 by pleveque          #+#    #+#             */
/*   Updated: 2021/12/06 15:33:50 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_fd_recu(unsigned int n, int fd, int	*i_ptr)
{
	if (n != 0)
	{
		*i_ptr += 1;
		ft_putnbr_fd_recu(n / 10, fd, i_ptr);
		ft_putchar_fd('0' + n % 10, fd);
	}
}

int	ft_putnbr_uns_fd(unsigned int n, int fd)
{
	int	iteration;
	int	*i_ptr;

	i_ptr = &iteration;
	iteration = 0;
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return (1);
	}
	ft_putnbr_fd_recu(n, fd, i_ptr);
	return (iteration);
}
