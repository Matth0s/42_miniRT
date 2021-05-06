/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 06:14:17 by mmoreira          #+#    #+#             */
/*   Updated: 2021/04/20 02:43:33 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *s)
{
	char	*temp;

	temp = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!(temp))
		return (NULL);
	ft_strlcpy(temp, (const char *)s, ft_strlen(s) + 1);
	return (temp);
}
