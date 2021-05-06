/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 18:44:30 by mmoreira          #+#    #+#             */
/*   Updated: 2021/04/20 03:22:33 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	print_string(va_list args, int *i, t_flag flag)
{
	char	*ptr;

	ptr = va_arg(args, char *);
	if (!(ptr))
		ptr = "(null)";
	if (flag.press < 0 || flag.press > (int)ft_strlen(ptr))
		flag.press = (int)ft_strlen(ptr);
	if (flag.width < flag.press)
		flag.width = flag.press;
	if (flag.sin)
		while_print(ptr, flag.press, 0);
	if (flag.zero)
		while_print(ptr, flag.width - flag.press, 2);
	else
		while_print(ptr, flag.width - flag.press, 1);
	if (!(flag.sin))
		while_print(ptr, flag.press, 0);
	*i += flag.j;
	return (flag.width);
}
