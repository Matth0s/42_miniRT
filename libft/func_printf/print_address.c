/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 18:44:15 by mmoreira          #+#    #+#             */
/*   Updated: 2021/04/20 03:22:01 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	make_str(unsigned long n, unsigned long p, char *base, char **temp)
{
	unsigned long	num;
	unsigned long	cont;

	cont = 0;
	num = n;
	while (p > 0)
	{
		*(*temp + cont) = base[num / p];
		num = num % p;
		p /= 16;
		cont++;
	}
}

static char	*ft_ultoa_base(unsigned long n, char *base)
{
	unsigned long	cont;
	unsigned long	num;
	unsigned long	pot;
	char			*temp;

	num = n;
	cont = 1;
	while (num >= 16 && cont++)
		num /= 16;
	temp = malloc((cont + 1) * sizeof(char));
	if (!(temp))
		return (NULL);
	*(temp + cont) = '\0';
	pot = 1;
	while (--cont)
		pot *= 16;
	make_str(n, pot, base, &temp);
	return (temp);
}

static void	print_address2(char *ptr, t_flag flag)
{
	if (flag.sin)
	{
		write(1, "0x", 2);
		while_print(ptr, flag.press - (int)ft_strlen(ptr), 2);
		while_print(ptr, (int)ft_strlen(ptr), 0);
	}
	if (flag.zero)
	{
		write(1, "0x", 2);
		while_print(ptr, flag.width - flag.press - 2, 2);
	}
	else
		while_print(ptr, flag.width - flag.press - 2, 1);
	if (!(flag.sin))
	{
		if (!(flag.zero))
			write(1, "0x", 2);
		while_print(ptr, flag.press - (int)ft_strlen(ptr), 2);
		while_print(ptr, (int)ft_strlen(ptr), 0);
	}
}

int	print_address(va_list args, int *i, t_flag flag)
{
	char	*ptr;

	ptr = ft_ultoa_base(va_arg(args, unsigned long), "0123456789abcdef");
	if (!(*ptr == '0' && flag.press == 0))
	{
		if (flag.press < (int)ft_strlen(ptr))
			flag.press = (int)ft_strlen(ptr);
		if (flag.width < flag.press + 2)
			flag.width = flag.press + 2;
		print_address2(ptr, flag);
	}
	else
	{
		if (flag.width < 2)
			flag.width = 2;
		if (flag.sin)
			write(1, "0x", 2);
		while_print(ptr, flag.width - 2, 1);
		if (!(flag.sin))
			write(1, "0x", 2);
	}
	*i += flag.j;
	free(ptr);
	return (flag.width);
}
