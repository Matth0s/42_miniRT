/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   while_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 18:44:37 by mmoreira          #+#    #+#             */
/*   Updated: 2021/03/21 11:46:35 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	while_print(char *str, int len, int sig)
{
	int	j;

	j = 0;
	if (sig == 0)
		while (j++ < len)
			ft_putchar_fd(*(str + j - 1), 1);
	else if (sig == 1)
		while (j++ < len)
			ft_putchar_fd(' ', 1);
	else
		while (j++ < len)
			ft_putchar_fd('0', 1);
}
