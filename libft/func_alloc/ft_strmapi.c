/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:40:25 by mmoreira          #+#    #+#             */
/*   Updated: 2021/09/20 10:13:52 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*temp;
	int		i;

	if (!(s))
		return (NULL);
	temp = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!(temp))
		return (NULL);
	i = 0;
	while (*(char *)(s + i) != '\0')
	{
		*(temp + i) = f(i, *(char *)(s + i));
		i++;
	}
	*(temp + i) = '\0';
	return (temp);
}
