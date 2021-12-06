/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:10:51 by pleveque          #+#    #+#             */
/*   Updated: 2021/12/06 14:13:39 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	clear_options(t_options *options)
{
	options->minus = 0;
	options->zero = 0;
	options->hashtag = 0;
	options->space = 0;
	options->plus = 0;
	options->prec = -1;
	options->type = '\0';
	options->size = -1;
}

int	ft_assign_opt(char c, t_options *options)
{
	if (c == '-')
		options->minus = 1;
	else if (c == '0')
		options->zero = 1;
	else if (c == '#')
		options->hashtag = 1;
	else if (c == ' ')
		options->space = 1;
	else if (c == '+')
		options->plus = 1;
	else
		return (0);
	return (1);
}

int	ft_count_digits(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	return (i);
}

int	parse_printf_options(const char *src, t_options *options)
{
	unsigned int	i;

	i = 1;
	clear_options(options);
	while ((ft_arrinclude(src[i], "-0# +.") || ft_isdigit(src[i])))
	{
		i += ft_assign_opt(src[i], options);
		if (ft_isdigit(src[i]))
		{
			options->size = ft_atoi(&src[i]);
			i += ft_count_digits(&src[i]);
		}
		if (src[i] == '.')
		{
			i++;
			options->prec = 0;
			if (ft_isdigit(src[i]))
				options->prec = ft_atoi(&src[i]);
			i += ft_count_digits(&src[i]);
		}
	}
	if (!ft_arrinclude(src[i], "cspdiuxX%"))
		return (0);
	options->type = src[i];
	return (i);
}
