/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:52:58 by pleveque          #+#    #+#             */
/*   Updated: 2021/12/05 13:12:31 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include	<stdio.h>
# include	<stdlib.h>
# include	<unistd.h>
# include	<fcntl.h>
# include <stdarg.h>
# include "../libft/libft.h"

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
int		ft_realloc_l_cat(char *src, int src_size, char **dst, int dst_size);
char	*printf_int(int arg);
char	*printf_char(int arg);
char	*printf_pointer(unsigned long long arg);
char	*printf_str(char *arg);
int		ft_printf(const char *src, ...);
int		parse_printf_options(const char *src, t_options *options);
char	*prefix_router(t_options *options, char *content, void *arg, int *c_size);
char	*ft_realloc_trunc(char *src, int len);
int		ft_realloc_merge(char **store, int nb_str, ...);


#endif