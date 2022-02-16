/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 18:06:03 by mmoreira          #+#    #+#             */
/*   Updated: 2021/09/20 13:29:00 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*temp;

	if (!s1 || !s2)
		return (NULL);
	temp = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!(temp))
		return (NULL);
	ft_strlcpy(temp, s1, (ft_strlen(s1) + 1));
	ft_strlcat(temp, s2, (ft_strlen(s1) + ft_strlen(s2) + 1));
	return (temp);
}
