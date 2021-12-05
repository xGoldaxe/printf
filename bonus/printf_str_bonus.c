/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_str_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:45:05 by pleveque          #+#    #+#             */
/*   Updated: 2021/12/05 15:48:30 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*printf_str(char *arg, int precision)
{
	char	*str;

	str = (char *)arg;
	if (!arg)
	{	
		if (precision == -1)
			return (ft_strdup("(null)"));
		return (ft_strldup("(null)", precision));
	}
	if (precision == -1)
		return (ft_strdup(str));
	return (ft_strldup(str, precision));
}
