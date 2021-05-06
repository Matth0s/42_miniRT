/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 01:02:48 by mmoreira          #+#    #+#             */
/*   Updated: 2021/04/20 03:09:35 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*temp1;
	unsigned char	*temp2;
	size_t			i;

	temp1 = (unsigned char *)str1;
	temp2 = (unsigned char *)str2;
	if (n == 0)
		return (0);
	i = 0;
	while (i < n - 1)
	{
		if (*(temp1 + i) != *(temp2 + i))
			return (*(temp1 + i) - *(temp2 + i));
		i++;
	}
	return (*(temp1 + i) - *(temp2 + i));
}
