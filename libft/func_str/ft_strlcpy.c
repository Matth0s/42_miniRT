/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:53:38 by mmoreira          #+#    #+#             */
/*   Updated: 2021/09/20 10:16:41 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (!src)
		return (0);
	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (*(char *)(src + i) != '\0' && i < size - 1)
	{
		*(char *)(dst + i) = *(char *)(src + i);
		i++;
	}
	*(char *)(dst + i) = '\0';
	return (ft_strlen(src));
}
