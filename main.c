/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:51:50 by pleveque          #+#    #+#             */
/*   Updated: 2021/12/02 19:55:30 by pleveque         ###   ########.fr       */
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
	char			*content;
	va_list			marker;
	va_list			copy;
	t_options		options;

	va_start(marker, src);
	va_copy(copy, marker);
	i = 0;
	res = 0;
	while (src[i])
	{
		if (src[i] == '%')
		{
			i++;
			options = parse_printf_options(src[i]);
			content = printf_router(options.type, copy, options);
			prefix_router(options.type, content);
			ft_putstr_fd(content, 1);
			suffix_router(options.type, content, options);
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
	char	*test = "ssalut";

	printf("|% 4d|", 151);
	//printf("res: %d\n", ft_printf("%d", 151));
}
