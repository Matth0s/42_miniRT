/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:55:58 by mmoreira          #+#    #+#             */
/*   Updated: 2021/09/20 10:16:50 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (i < len && *(unsigned char *)(big + i) != '\0')
	{
		k = i;
		j = 0;
		while (*(unsigned char *)(big + i) == *(unsigned char *)(little + j))
		{
			if (i++ == len && *(unsigned char *)(little + j) != '\0')
				return (NULL);
			else if (*(unsigned char *)(little + 1 + j++) == '\0')
				return ((char *)(big + k));
		}
		i = k;
		i++;
	}
	return (NULL);
}
