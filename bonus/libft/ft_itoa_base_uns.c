/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_uns.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:53:14 by pleveque          #+#    #+#             */
/*   Updated: 2021/12/04 16:24:17 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long long	count_itoa(unsigned long long n, char *base)
{
	unsigned long long	i;
	size_t				base_size;

	base_size = ft_strlen(base);
	if (n == 0)
		return (1);
	i = 0;
	while (n != 0)
	{
		n = n / base_size;
		i++;
	}
	return (i);
}

static char	*ft_build_itoa(char *res, unsigned long long len,
unsigned long long n, char *base)
{
	unsigned long long	i;
	size_t				base_size;

	if (n == 0)
		res[0] = '0';
	base_size = ft_strlen(base);
	i = 0;
	while (n != 0)
	{
		res[len - i - 1] = base[n % base_size];
		n = n / base_size;
		i++;
	}
	res[len] = '\0';
	return (res);
}

char	*ft_itoa_base_uns(unsigned long long n, char *base)
{
	char				*res;
	unsigned long long	len;

	len = count_itoa(n, base);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	return (ft_build_itoa(res, len, n, base));
}
