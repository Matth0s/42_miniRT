/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 16:01:46 by mmoreira          #+#    #+#             */
/*   Updated: 2021/04/20 03:12:42 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_free_split(char **str)
{
	int	i;

	i = 0;
	while (*(str + i++) != NULL)
	{
		free(*(str + i - 1));
		*(str + i - 1) = NULL;
	}
	free(str);
	str = NULL;
}
