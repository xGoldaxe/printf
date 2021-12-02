/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:52:58 by pleveque          #+#    #+#             */
/*   Updated: 2021/12/02 19:59:56 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include	<stdio.h>
# include	<stdlib.h>
# include	<unistd.h>
# include	<fcntl.h>
# include <stdarg.h>
# include "./libft/libft.h"

typedef struct s_options
{
	char	type;
	int		minus;
	int		zero;
	int		point;
	int		hashtag;
	int		space;
	int		plus;
}	t_options;

int	printf_percentage(const char src);
int	printf_str(va_list argptr);
int	printf_int(va_list argptr);
int	printf_char(va_list argptr);
int	printf_hexa(va_list argptr, char *base);
int	printf_uns_int(va_list argptr);
int	printf_pointer(va_list argptr);
int	ft_printf(const char *src, ...);

#endif