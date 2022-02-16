/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 10:06:46 by mmoreira          #+#    #+#             */
/*   Updated: 2021/09/21 22:36:55 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_addchar(char *str, char c)
{
	char	*temp;
	int		i;

	if (!(str))
		temp = malloc(2 * sizeof(char));
	else
		temp = malloc((ft_strlen(str) + 2) * sizeof(char));
	if (!(temp))
		return (NULL);
	i = -1;
	if (str)
	{
		while (*(str + ++i))
			*(temp + i) = *(str + i);
		free(str);
	}
	*(temp + i) = c;
	*(temp + i + 1) = '\0';
	return (temp);
}
