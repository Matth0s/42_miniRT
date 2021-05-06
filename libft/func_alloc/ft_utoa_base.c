/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 12:44:47 by mmoreira          #+#    #+#             */
/*   Updated: 2021/04/20 02:50:32 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	make_str(unsigned int n, char *base, unsigned int pot, char **temp)
{
	unsigned int	num;
	unsigned int	cont;

	cont = 0;
	num = n;
	while (pot > 0)
	{
		*(*temp + cont) = base[num / pot];
		num = num % pot;
		pot /= (unsigned int)ft_strlen(base);
		cont++;
	}
}

char	*ft_utoa_base(unsigned int n, char *base)
{
	unsigned int	cont;
	unsigned int	num;
	unsigned int	pot;
	char			*temp;

	if (ft_check_base(base))
		return (NULL);
	num = n;
	cont = 1;
	while (num >= (unsigned int)ft_strlen(base) && cont++)
		num /= (unsigned int)ft_strlen(base);
	temp = malloc((cont + 1) * sizeof(char));
	if (!(temp))
		return (NULL);
	*(temp + cont) = '\0';
	pot = 1;
	while (--cont)
		pot *= (unsigned int)ft_strlen(base);
	make_str(n, base, pot, &temp);
	return (temp);
}
