/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 18:44:26 by mmoreira          #+#    #+#             */
/*   Updated: 2021/04/20 03:22:17 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	print_int3(char *ptr, t_flag flag, int ind)
{
	if (flag.sin)
	{
		if (ind)
			ft_putchar_fd('-', 1);
		while_print(ptr, flag.press - (int)ft_strlen(ptr), 2);
		while_print(ptr, (int)ft_strlen(ptr), 0);
	}
	if (flag.zero)
	{
		if (ind)
			ft_putchar_fd('-', 1);
		while_print(ptr, flag.width - flag.press, 2);
	}
	else
		while_print(ptr, flag.width - flag.press, 1);
	if (!(flag.sin))
	{
		if (ind && !(flag.zero))
			ft_putchar_fd('-', 1);
		while_print(ptr, flag.press - (int)ft_strlen(ptr), 2);
		while_print(ptr, (int)ft_strlen(ptr), 0);
	}
}

static int	print_int2(char *ptr, t_flag flag, int ind)
{
	if (!(*ptr == '0' && flag.press == 0))
	{
		if (flag.press < (int)ft_strlen(ptr))
			flag.press = (int)ft_strlen(ptr);
		if (flag.width < flag.press)
			flag.width = flag.press;
		if (ind)
			flag.width -= 1;
		print_int3(ptr, flag, ind);
		if (ind && flag.width + 1 <= flag.press)
			flag.width += 2;
		else if (ind && flag.width + 1 > flag.press)
			flag.width += 1;
	}
	else
	{
		if (flag.width < 1)
			flag.width = 0;
		while_print(ptr, flag.width, 1);
	}
	return (flag.width);
}

int	print_int(va_list args, int *i, t_flag flag)
{
	char	*ptr;
	int		ind;
	int		j;

	j = va_arg(args, int);
	ind = 0;
	if (j < 0)
	{
		ind = 1;
		ptr = ft_utoa(-j);
	}
	else
		ptr = ft_utoa(j);
	flag.width = print_int2(ptr, flag, ind);
	*i += flag.j;
	free(ptr);
	return (flag.width);
}
