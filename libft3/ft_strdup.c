/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:18:30 by pleveque          #+#    #+#             */
/*   Updated: 2021/11/25 17:24:02 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*newstr;

	newstr = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (newstr == NULL)
		return (NULL);
	ft_strlcpy(newstr, s, ft_strlen(s) + 1);
	return (newstr);
}
