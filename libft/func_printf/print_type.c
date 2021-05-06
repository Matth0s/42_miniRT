/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 18:43:45 by mmoreira          #+#    #+#             */
/*   Updated: 2021/04/20 03:19:24 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	print_type(const char *str, va_list args, int *i, t_flag flag)
{
	if (*(str + *i + flag.j) == 'c')
		return (print_char(va_arg(args, int), i, flag));
	else if (*(str + *i + flag.j) == 's')
		return (print_string(args, i, flag));
	else if (*(str + *i + flag.j) == 'd' || *(str + *i + flag.j) == 'i')
		return (print_int(args, i, flag));
	else if (*(str + *i + flag.j) == 'u')
		return (print_uint(args, i, flag));
	else if (*(str + *i + flag.j) == 'x')
		return (print_hex(args, i, flag, 0));
	else if (*(str + *i + flag.j) == 'X')
		return (print_hex(args, i, flag, 1));
	else if (*(str + *i + flag.j) == 'p')
		return (print_address(args, i, flag));
	else if (*(str + *i + flag.j) == '%')
		return (print_char('%', i, flag));
	else
		write(1, "%", 1);
	return (1);
}
