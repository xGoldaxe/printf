/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:51:50 by pleveque          #+#    #+#             */
/*   Updated: 2021/12/04 15:01:36 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_router(const char src, va_list argptr)
{
	if (src == '%')
		return (printf_percentage(src));
	else if (src == 'c')
		return (printf_char(argptr));
	else if (src == 's')
		return (printf_str(argptr));
	else if (src == 'p')
		return (printf_pointer(argptr));
	else if (src == 'd')
		return (printf_int(argptr));
	else if (src == 'i')
		return (printf_int(argptr));
	else if (src == 'u')
		return (printf_uns_int(argptr));
	else if (src == 'x')
		return (printf_hexa(argptr, "0123456789abcdef"));
	else if (src == 'X')
		return (printf_hexa(argptr, "0123456789ABCDEF"));
	return (-1);
}

int	ft_printf(const char *src, ...)
{
	unsigned int	i;
	unsigned int	res;
	int				tmp;
	va_list			marker;
	va_list			copy;

	va_start(marker, src);
	va_copy(copy, marker);
	i = 0;
	res = 0;
	while (src[i])
	{
		if (src[i] == '%')
		{
			i++;
			tmp = printf_router(src[i], copy);
			if (tmp == -1)
				return (-1);
			res += tmp;
		}
		else
		{
			res++;
			write(1, &src[i], 1);
		}
		i++;
	}
	return (res);
}

int	main(void)
{
	printf("{%d}\n", ft_printf("%c%c%c ", '2', '1', 0));
	printf("{%d}", printf("%c%c%c ", '2', '1', 0));
}