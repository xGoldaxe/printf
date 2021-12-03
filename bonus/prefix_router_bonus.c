/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefix_router_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:04:10 by pleveque          #+#    #+#             */
/*   Updated: 2021/12/03 21:34:26 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*prefix_precision(t_options *options, char *content, void *arg)
{
	int				i;
	char			*prefix;
	unsigned int	content_size;

	(void)arg;
	content_size = ft_strlen(content);
	prefix = NULL;
	i = options->size - content_size;
	if (ft_arrinclude(options->type, "diuxX"))
	{
		while (i > 0)
		{
			prefix = ft_realloc_cat("0", prefix);
			i--;
		}
		prefix = ft_realloc_cat(content, prefix);
		free(content);
		return (prefix);
	}
	else if (options->type == 's')
		return (ft_realloc_trunc(content, options->size));
	return (NULL);
}

char	*prefix_size(t_options *options, char *content, void *arg)
{
	int				i;
	char			*prefix;
	unsigned int	content_size;

	(void)arg;
	content_size = ft_strlen(content);
	prefix = NULL;
	i = options->size - content_size;
	while (i > 0)
	{
		if (options->zero && !options->minus)
			prefix = ft_realloc_cat("0", prefix);
		else
			prefix = ft_realloc_cat(" ", prefix);
		i--;
	}
	if (options->minus)
	{
		content = ft_realloc_cat(prefix, content);
		return (content);
	}
	prefix = ft_realloc_cat(content, prefix);
	return (prefix);
}

char	*prefix_router(t_options *options, char *content, void *arg)
{
	char			*prefix;
	unsigned int	content_size;

	content_size = ft_strlen(content);
	prefix = NULL;
	if (!options->precision)
		prefix = prefix_size(options, content, arg);
	else
		prefix = prefix_precision(options, content, arg);
	return (prefix);
}
