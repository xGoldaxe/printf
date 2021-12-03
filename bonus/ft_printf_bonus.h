/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:52:58 by pleveque          #+#    #+#             */
/*   Updated: 2021/12/03 21:32:59 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include	<stdio.h>
# include	<stdlib.h>
# include	<unistd.h>
# include	<fcntl.h>
# include <stdarg.h>
# include "./libft/libft.h"

typedef struct s_options
{
	char	type;
	int		precision;
	int		minus;
	int		zero;
	int		point;
	int		hashtag;
	int		space;
	int		size;
	int		plus;
}	t_options;

int		printf_percentage(const char src);
int		printf_str(va_list argptr);
char	*printf_int(int arg);
char	*printf_char(int arg);
char	*printf_pointer(void *arg);
int		ft_printf(const char *src, ...);
int		parse_printf_options(const char *src, t_options *options);
char	*prefix_router(t_options *options,
			char *content, void *arg);
char	*ft_realloc_trunc(char *src, int len);

#endif