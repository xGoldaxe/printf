/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:51:50 by pleveque          #+#    #+#             */
/*   Updated: 2021/12/05 16:23:49 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*printf_router(t_options *options, void *arg, int *size)
{
	char	*res;

	res = NULL;
	if (options->type == '%')
		res = ft_strdup("%");
	if (options->type == 'c')
		res = printf_char(*(int *)arg);
	else if (options->type == 's')
		res = printf_str((char *)arg, options->precision);
	else if (options->type == 'p')
		res = printf_pointer(*(unsigned long long *)arg);
	else if (options->type == 'd' || options->type == 'i')
		res = printf_int(ft_itoa(*(int *)arg), options->precision);
	else if (options->type == 'u')
		res = printf_int(ft_itoa_base_uns(*(unsigned int *)arg,
					"0123456789"), options->precision);
	else if (options->type == 'x')
		res = printf_int(ft_itoa_base_uns(*(unsigned int *)arg,
					"0123456789abcdef"), options->precision);
	else if (options->type == 'X')
		res = printf_int(ft_itoa_base_uns(*(unsigned int *)arg,
					"0123456789ABCDEF"), options->precision);
	if (options->type == 'c')
		*size += 1;
	else
		*size += ft_strlen(res);
	return (res);
}

void	*get_arg(va_list argptr, char type)
{
	int				*i;
	unsigned long	*llu;
	char			*str;

	if (type == 'p')
	{
		llu = malloc(sizeof(unsigned long));
		*llu = va_arg(argptr, unsigned long);
		return (llu);
	}
	if (type == 's')
	{
		str = va_arg(argptr, char *);
		if (str)
			return (ft_strdup(str));
		else
			return (NULL);
	}
	i = malloc(sizeof(int));
	*i = va_arg(argptr, int);
	return (i);
}

int	ft_printf(const char *src, ...)
{
	int				i;
	int				res;
	int				tmp;
	char			*content;
	va_list			copy;
	t_options		*options;
	t_options		opt;
	void	*arg;

	va_start(copy, src);
	options = &opt;
	i = 0;
	res = 0;
	while (src[i])
	{
		if (src[i] == '%')
		{
			tmp = 0;
			arg = NULL;
			i += parse_printf_options(&src[i], options);
			if (options->type != '%')
				arg = get_arg(copy, options->type);
			content = printf_router(options, arg, &tmp);
			content = prefix_router(options, content, arg, &tmp);
			write(1, content, tmp);
			free(content);
			free(arg);
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

//int	main(void)
//{
//	int	*test;

//	printf("\n{%d}\n", ft_printf("this is 1 %s with %s %s", "test", "multiple", "strings"));
//	printf("\n{%d}\n", printf("this is 1 %s with %s %s", "test", "multiple", "strings"));
//}
