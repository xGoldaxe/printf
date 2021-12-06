/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_uns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:53:14 by pleveque          #+#    #+#             */
/*   Updated: 2021/12/06 14:41:36 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static unsigned long long	count_itoa(unsigned long long n)
{
	unsigned long long	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_build_itoa(char *res, unsigned long long len,
unsigned long long n)
{
	unsigned long long	i;

	i = 0;
	while (n != 0)
	{
		res[len - i - 1] = '0' + (n % 10);
		n = n / 10;
		i++;
	}
	res[len] = '\0';
	return (res);
}

char	*ft_itoa_uns(unsigned long long n)
{
	char				*res;
	unsigned long long	len;

	len = count_itoa(n);
	if (n < 0)
		len++;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	return (ft_build_itoa(res, len, n));
}
