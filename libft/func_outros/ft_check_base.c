/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:40:06 by mmoreira          #+#    #+#             */
/*   Updated: 2021/04/21 02:34:08 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	check_base_loop(char *base, int i)
{
	char	*base_c;
	int		j;

	base_c = malloc((ft_strlen(base) + 1) * sizeof(char));
	if (!(base_c))
		return (0);
	i = 0;
	*(base_c + i) = '\0';
	while (*(base + i) != '\0')
	{
		j = 0;
		while (*(base_c + j++) != '\0')
		{
			if (*(base + i) == *(base_c + j - 1))
			{
				free(base_c);
				return (0);
			}
		}
		*(base_c + j) = *(base + i);
		*(base_c + j + 1) = '\0';
		i++;
	}
	free(base_c);
	return (1);
}

int	ft_check_base(char *base)
{
	int	i;

	i = 0;
	if (!(base) || ft_strlen(base) == 1)
		return (0);
	while (*(base + i++) != '\0')
		if (*(base + i - 1) || *(base + i - 1) == '+')
			return (0);
	return (check_base_loop(base, i));
}
