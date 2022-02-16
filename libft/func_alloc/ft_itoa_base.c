/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 12:44:47 by mmoreira          #+#    #+#             */
/*   Updated: 2021/09/20 10:13:04 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	make_str(int n, char *base, unsigned int pot, char **temp)
{
	unsigned int	num;
	unsigned int	cont;

	if (n < 0)
	{
		cont = 1;
		num = -n;
	}
	else
	{
		cont = 0;
		num = n;
	}
	while (pot > 0)
	{
		*(*temp + cont) = base[num / pot];
		num = num % pot;
		pot /= (int)ft_strlen(base);
		cont++;
	}
	if (n < 0)
		*(*temp) = '-';
}

char	*ft_itoa_base(int n, char *base)
{
	unsigned int	cont;
	unsigned int	pot;
	char			*temp;

	if (ft_check_base(base))
		return (NULL);
	cont = ft_numlen((int)ft_strlen(base), n);
	temp = malloc((cont + 1) * sizeof(char));
	if (!(temp))
		return (NULL);
	*(temp + cont) = '\0';
	pot = 1;
	while (--cont)
		pot *= (int)ft_strlen(base);
	if (n < 0)
		pot /= (int)ft_strlen(base);
	make_str(n, base, pot, &temp);
	return (temp);
}
