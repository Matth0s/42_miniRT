/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:54:56 by mmoreira          #+#    #+#             */
/*   Updated: 2021/09/20 10:16:38 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dst);
	j = 0;
	if (i >= size)
		return (size + ft_strlen(src));
	while (*(char *)(src + j) != '\0' && i + j < size - 1)
	{
		*(char *)(dst + i + j) = *(char *)(src + j);
		j++;
	}
	*(char *)(dst + i + j) = '\0';
	return (i + ft_strlen(src));
}
