/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:10:51 by pleveque          #+#    #+#             */
/*   Updated: 2021/12/03 21:34:30 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	clear_options(t_options *options)
{
	options->minus = 0;
	options->zero = 0;
	options->point = 0;
	options->hashtag = 0;
	options->space = 0;
	options->plus = 0;
	options->precision = 0;
	options->type = '\0';
	options->size = -1;
}

int	parse_printf_options(const char *src, t_options *options)
{
	unsigned int	i;

	i = 1;
	clear_options(options);
	while (ft_arrinclude(src[i], "-0# +") && src[i] != '.')
	{
		if (src[i] == '-')
			options->minus = 1;
		if (src[i] == '0')
			options->zero = 1;
		if (src[i] == '.')
			options->point = 1;
		if (src[i] == '#')
			options->hashtag = 1;
		if (src[i] == ' ')
			options->space = 1;
		if (src[i] == '+')
			options->plus = 1;
		i++;
	}
	if (src[i] == '.')
	{
		options->precision = 1;
		options->size = 0;
		i++;
	}
	if (ft_isdigit(src[i]))
		options->size = ft_atoi(&src[i]);
	while (ft_isdigit(src[i]))
		i++;
	if (!ft_arrinclude(src[i], "cspdiuxX%"))
		return (0);
	options->type = src[i];
	return (i);
}
