/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 18:15:18 by mmoreira          #+#    #+#             */
/*   Updated: 2021/09/20 10:16:31 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	num;
	int	sin;

	i = 0;
	num = 0;
	sin = 1;
	while (ft_isspace(*(nptr + i)))
		i++;
	if (*(nptr + i) == '-' || *(nptr + i) == '+')
	{
		if (*(nptr + i) == '-')
			sin *= -1;
		i++;
	}
	while (ft_isdigit(*(nptr + i)))
	{
		num = (num * 10) + (*(nptr + i) - '0');
		i++;
	}
	return (num * sin);
}
