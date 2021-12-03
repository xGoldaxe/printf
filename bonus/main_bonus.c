/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:51:50 by pleveque          #+#    #+#             */
/*   Updated: 2021/12/03 21:34:34 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*printf_router(const char type, void *arg)
{
	if (type == '%')
		return (ft_strdup("%"));
	if (type == 'c')
		return (printf_char(*(int *)arg));
	else if (type == 's')
		return (ft_strdup((char *)arg));
	else if (type == 'p')
		return (printf_pointer(arg));
	else if (type == 'd' || type == 'i')
		return (ft_itoa(*(int *)arg));
	else if (type == 'u')
		return (ft_itoa_base_uns(*(unsigned int *)arg, "0123456789"));
	else if (type == 'x')
		return (ft_itoa_base_uns(*(unsigned int *)arg, "0123456789abcdef"));
	else if (type == 'X')
		return (ft_itoa_base_uns(*(unsigned int *)arg, "0123456789ABCDEF"));
	return (NULL);
}

void	*get_arg(va_list argptr, char type)
{
	void					*result;
	int						i;
	unsigned long long	llu;
	char					*str;

	if (type == 'p')
	{
		llu = va_arg(argptr, unsigned long long);
		if (!llu)
			return (NULL);
		result = &llu;
		return (result);
	}
	else if (type == 's')
	{
		str = va_arg(argptr, char *);
		result = str;
		return (result);
	}
	i = va_arg(argptr, int);
	result = &i;
	return (result);
}

int	ft_printf(const char *src, ...)
{
	unsigned int	i;
	unsigned int	res;
	char			*content;
	va_list			marker;
	va_list			copy;
	t_options		*options;
	t_options		opt;
	void	*arg;

	va_start(marker, src);
	va_copy(copy, marker);
	options = &opt;
	i = 0;
	res = 0;
	while (src[i])
	{
		if (src[i] == '%')
		{
			i += parse_printf_options(&src[i], options);
			arg = get_arg(copy, options->type);
			content = printf_router(options->type, arg);
			if (!content)
				return (-1);
			content = prefix_router(options, content, arg);
			ft_putstr_fd(content, 1);
			res += ft_strlen(content);
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
//	//printf("|%c|", a);
//	//printf("res: %d\n", ft_printf("%c", 'a'));
//	//ft_printf("%u", 94561515181954);
//	//printf("\n|% 05d|", 5);
//	//printf("|%5s|", "salut");
//	ft_printf("\ncount: %d", ft_printf("|%60c|", 'a'));
//	//printf("\n|%.3s|", "salut");
//}
