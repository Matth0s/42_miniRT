/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 18:44:18 by mmoreira          #+#    #+#             */
/*   Updated: 2021/03/21 11:46:19 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	print_char(int c, int *i, t_flag flag)
{
	char	*ptr;

	ptr = NULL;
	if (flag.width < 1)
		flag.width = 1;
	if (flag.sin)
		ft_putchar_fd(c, 1);
	if (flag.zero)
		while_print(ptr, flag.width - 1, 2);
	else
		while_print(ptr, flag.width - 1, 1);
	if (!(flag.sin))
		ft_putchar_fd(c, 1);
	*i += flag.j;
	return (flag.width);
}
