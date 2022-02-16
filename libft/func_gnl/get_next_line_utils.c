/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 13:34:22 by mmoreira          #+#    #+#             */
/*   Updated: 2021/09/20 10:14:45 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	str_len(char *s)
{
	size_t	i;

	i = 0;
	if (!(s))
		return (i);
	while (*(s + i) != '\0')
		i++;
	return (i);
}

size_t	str_copy(char *dst, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!(src))
		return (0);
	if (size == 0)
		return (str_len(src));
	while (*(src + i) != '\0' && i < size - 1)
	{
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = '\0';
	return (str_len(src));
}

char	*str_join(char *s1, char *s2)
{
	char	*temp;

	if (!s1 && !s2)
		return (NULL);
	temp = malloc((str_len(s1) + str_len(s2) + 1) * sizeof(char));
	if (!(temp))
		return (NULL);
	str_copy(temp, s1, (str_len(s1) + 1));
	str_copy((temp + str_len(s1)), s2, (str_len(s2) + 1));
	free(s1);
	return (temp);
}

char	*str_dup(char *s)
{
	char	*temp;

	temp = malloc((str_len(s) + 1) * sizeof(char));
	if (!(temp))
		return (NULL);
	str_copy(temp, s, str_len(s) + 1);
	return (temp);
}
