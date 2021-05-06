/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 20:48:33 by mmoreira          #+#    #+#             */
/*   Updated: 2021/04/20 03:23:37 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (*(s + i) != '\0' && *(s + i) != (unsigned char)c)
		i++;
	if (*(s + i) == '\0' && (unsigned char)c != '\0')
		return (NULL);
	return ((char *)(s + i));
}
