/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numdigt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 17:17:57 by mmoreira          #+#    #+#             */
/*   Updated: 2021/03/19 15:57:28 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen(int unsigned base, int n)
{
	unsigned int	cont;
	unsigned int	num;

	if (n < 0)
	{
		num = -n;
		cont = 2;
	}
	else
	{
		num = n;
		cont = 1;
	}
	while (num >= base && cont++)
		num /= base;
	return (cont);
}
