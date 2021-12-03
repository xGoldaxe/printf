/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_str_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:45:05 by pleveque          #+#    #+#             */
/*   Updated: 2021/12/03 21:34:09 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	printf_str(va_list argptr)
{
	unsigned int	i;
	char			*str;

	str = va_arg(argptr, char *);
	if (str)
	{
		i = 0;
		while (str[i] != '\0')
		{
			write(1, &str[i], 1);
			i++;
		}
		return (i);
	}
	write(1, "(null)", 6);
	return (6);
}
