/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:14:50 by mmoreira          #+#    #+#             */
/*   Updated: 2021/09/20 10:14:05 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa(unsigned int n)
{
	unsigned int	cont;
	unsigned int	num;
	char			*temp;

	cont = 1;
	num = n;
	while (n >= 10 && cont++)
		n /= 10;
	temp = malloc((cont + 1) * sizeof(char));
	if (!(temp))
		return (NULL);
	*(temp + cont) = '\0';
	while (cont--)
	{
		*(temp + cont) = num % 10 + '0';
		num /= 10;
	}
	return (temp);
}
