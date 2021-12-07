/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:51:50 by pleveque          #+#    #+#             */
/*   Updated: 2021/12/06 15:11:58 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*printf_router(t_options *o, void *arg, int *size)
{
	char	*res;

	res = NULL;
	if (o->type == '%')
		res = ft_strdup("%");
	if (o->type == 'c')
		res = printf_char(*(int *)arg);
	else if (o->type == 's')
		res = printf_str((char *)arg, o->prec);
	else if (o->type == 'p')
		res = printf_pointer(*(unsigned long long *)arg);
	else if (o->type == 'd' || o->type == 'i')
		res = printf_int(ft_itoa(*(int *)arg), o->prec, *(int *)arg == 0);
	else if (o->type == 'u')
		res = printf_int(ft_itoa_base_uns(*(unsigned int *)arg,
					"0123456789"), o->prec, *(unsigned int *)arg == 0);
	else if (o->type == 'x')
		res = printf_int(ft_itoa_base_uns(*(unsigned int *)arg,
					"0123456789abcdef"), o->prec, *(unsigned int *)arg == 0);
	else if (o->type == 'X')
		res = printf_int(ft_itoa_base_uns(*(unsigned int *)arg,
					"0123456789ABCDEF"), o->prec, *(unsigned int *)arg == 0);
	*size += add_ternary(o->type == 'c', 1, ft_strlen(res));
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

char	*build_printf(t_options *options, va_list marker, int *tmp)
{
	void	*arg;
	char	*content;

	arg = NULL;
	if (options->type != '%')
		arg = get_arg(marker, options->type);
	content = printf_router(options, arg, tmp);
	content = prefix_router(options, content, arg, tmp);
	if (arg)
		free(arg);
	return (content);
}

int	ft_iteration_printf(const char *src, va_list marker, t_options *options)
{	
	int				res;
	int				tmp;
	char			*content;

	res = 0;
	while (*src)
	{
		if (*src == '%')
		{
			tmp = 0;
			src += parse_printf_options(src, options);
			content = build_printf(options, marker, &tmp);
			if (!content)
				return (res);
			write(1, content, tmp);
			free(content);
			res += tmp;
		}
		else if (++res)
			write(1, src, 1);
		src++;
	}
	return (res);
}

int	ft_printf(const char *src, ...)
{
	va_list			marker;
	t_options		*options;
	t_options		opt;

	va_start(marker, src);
	options = &opt;
	return (ft_iteration_printf(src, marker, options));
}

//int	main(void)
//{
//	int	*test;

//	printf("\n{%d}\n", ft_printf("%.1s", NULL));
//	printf("\n{%d}\n", printf("%.1s", NULL));
//}
