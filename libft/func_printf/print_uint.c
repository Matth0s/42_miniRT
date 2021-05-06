/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 18:44:33 by mmoreira          #+#    #+#             */
/*   Updated: 2021/04/20 03:22:47 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	print_uint2(char *ptr, t_flag flag)
{
	if (flag.sin)
	{
		while_print(ptr, flag.press - (int)ft_strlen(ptr), 2);
		while_print(ptr, (int)ft_strlen(ptr), 0);
	}
	if (flag.zero)
		while_print(ptr, flag.width - flag.press, 2);
	else
		while_print(ptr, flag.width - flag.press, 1);
	if (!(flag.sin))
	{
		while_print(ptr, flag.press - (int)ft_strlen(ptr), 2);
		while_print(ptr, (int)ft_strlen(ptr), 0);
	}
}

int	print_uint(va_list args, int *i, t_flag flag)
{
	char	*ptr;

	ptr = ft_utoa(va_arg(args, unsigned int));
	if (!(*ptr == '0' && flag.press == 0))
	{
		if (flag.press < (int)ft_strlen(ptr))
			flag.press = (int)ft_strlen(ptr);
		if (flag.width < flag.press)
			flag.width = flag.press;
		print_uint2(ptr, flag);
	}
	else
	{
		if (flag.width < 1)
			flag.width = 0;
		while_print(ptr, flag.width, 1);
	}
	*i += flag.j;
	free(ptr);
	return (flag.width);
}
