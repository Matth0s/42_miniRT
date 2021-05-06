/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 18:12:10 by mmoreira          #+#    #+#             */
/*   Updated: 2021/03/18 16:41:54 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	pot;
	unsigned int	num;
	unsigned int	i;

	if (n < 0)
	{
		write(fd, "-", 1);
		num = -n;
	}
	else
		num = n;
	pot = 1;
	i = num;
	while (i >= 10)
	{
		i /= 10;
		pot *= 10;
	}
	while (pot > 0)
	{
		i = (num / pot) + '0';
		write(fd, &i, 1);
		num = num % pot;
		pot /= 10;
	}
}
