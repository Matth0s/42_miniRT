/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 00:58:18 by mmoreira          #+#    #+#             */
/*   Updated: 2021/09/27 00:59:47 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_splitlen(char **str)
{
	int	i;

	i = 0;
	if (!(str))
		return (i);
	while (*(str + i) != NULL)
		i++;
	return (i);
}
