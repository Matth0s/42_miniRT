/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:14:50 by mmoreira          #+#    #+#             */
/*   Updated: 2021/09/20 10:13:25 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	unsigned int	cont;
	unsigned int	num;
	char			*temp;

	cont = ft_numlen(10, n);
	temp = malloc((cont + 1) * sizeof(char));
	if (!(temp))
		return (NULL);
	*(temp + cont) = '\0';
	if (n < 0)
		num = -n;
	else
		num = n;
	while (cont--)
	{
		*(temp + cont) = num % 10 + '0';
		num /= 10;
	}
	if (n < 0)
		*temp = '-';
	return (temp);
}
