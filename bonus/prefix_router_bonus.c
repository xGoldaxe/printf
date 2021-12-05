/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefix_router_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:04:10 by pleveque          #+#    #+#             */
/*   Updated: 2021/12/05 19:00:40 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*ft_preprefix(t_options *options, void *arg)
{
	char	*preprefix;

	preprefix = NULL;
	if ((options->type == 'i' || options->type == 'd'))
	{
		if (*(int *)arg < 0)
			preprefix = ft_strdup("-");
		else if (options->plus)
			preprefix = ft_strdup("+");
		else if (options->space)
			preprefix = ft_strdup(" ");
	}
	else if ((options->type == 'x' || options->type == 'X')
		&& options->hashtag && *(unsigned int *)arg > 0)
	{
		if (options->type == 'x')
			preprefix = ft_strdup("0x");
		else if (options->type == 'X')
			preprefix = ft_strdup("0X");
	}
	return (preprefix);
}

char	*get_fill(t_options *options, int size)
{
	char	*fill;

	if (options->zero && !options->minus && options->precision == -1)
		fill = ft_strfill(size, '0');
	else
		fill = ft_strfill(size, ' ');
	return (fill);
}

char	*prefix_router(t_options *options, char *content,
void *arg, int *c_size)
{
	char			*fill;
	char			*preprefix;
	char			*res;

	res = NULL;
	fill = NULL;
	preprefix = ft_preprefix(options, arg);
	fill = get_fill(options, options->size - *c_size - ft_strlen(preprefix));
	if (options->minus)
		*c_size = ft_realloc_merge(&res, 3, preprefix, ft_strlen(preprefix),
				content, *c_size, fill, ft_strlen(fill));
	else if (options->zero && options->precision == -1)
		*c_size = ft_realloc_merge(&res, 3, preprefix, ft_strlen(preprefix),
				fill, ft_strlen(fill), content, *c_size);
	else
		*c_size = ft_realloc_merge(&res, 3, fill, ft_strlen(fill),
				preprefix, ft_strlen(preprefix), content, *c_size);
	free(content);
	free(fill);
	free(preprefix);
	return (res);
}
