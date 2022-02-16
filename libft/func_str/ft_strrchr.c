/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 21:24:17 by mmoreira          #+#    #+#             */
/*   Updated: 2021/09/20 10:16:52 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	while (0 < i && *(s + i) != (unsigned char)c)
		i--;
	if (i == 0 && *(s + i) != (unsigned char)c)
		return (NULL);
	return ((char *)(s + i));
}
