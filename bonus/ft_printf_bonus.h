/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:52:58 by pleveque          #+#    #+#             */
/*   Updated: 2021/12/05 18:50:48 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include	<stdio.h>
# include	<stdlib.h>
# include	<unistd.h>
# include	<fcntl.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_options
{
	char	type;
	int		precision;
	int		minus;
	int		zero;
	int		hashtag;
	int		space;
	int		size;
	int		plus;
}	t_options;

int		printf_percentage(const char src);
int		ft_realloc_l_cat(char *src, int src_size, char **dst, int dst_size);
char	*printf_int(char *content, int precision);
char	*printf_char(int arg);
char	*printf_str(char *arg, int precision);
char	*printf_pointer(unsigned long long arg);
int		ft_printf(const char *src, ...);
int		parse_printf_options(const char *src, t_options *options);
char	*prefix_router(t_options *options, char *content,
			void *arg, int *c_size);
int		ft_realloc_merge(char **store, int nb_str, ...);
char	*ft_strldup(const char *s, int size);
char	*ft_strfill(int size, char c);
int		add_ternary(int condition, int v1, int v2);

#endif