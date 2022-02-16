/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:44:08 by mmoreira          #+#    #+#             */
/*   Updated: 2021/09/20 10:15:54 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	check_sin_zero(const char *str, t_flag *flag, int *i)
{
	while (*(str + *i + (*flag).j) == '0' || *(str + *i + (*flag).j) == '-')
	{
		if (*(str + *i + (*flag).j) == '-')
		{
			(*flag).sin = 1;
			(*flag).zero = 0;
		}
		if (*(str + *i + (*flag).j) == '0' && (*flag).sin == 0)
			(*flag).zero = 1;
		(*flag).j++;
	}
}

static void	check_width(const char *str, va_list args, t_flag *flag, int *i)
{
	if (*(str + *i + (*flag).j) == '*')
	{
		(*flag).width = va_arg(args, int);
		if ((*flag).width < 0)
		{
			(*flag).width *= -1;
			(*flag).sin = 1;
			(*flag).zero = 0;
		}
		(*flag).j++;
	}
	else
	{
		if (ft_isdigit(*(str + *i + (*flag).j)))
		{
			(*flag).width = ft_atoi((str + *i + (*flag).j));
			(*flag).j += ft_numlen(10, (*flag).width);
		}
	}
}

static void	check_press_num(const char *str, t_flag **flag, int *i)
{
	int	k;

	k = 0;
	while (*(str + *i + (*(*flag)).j + k) == '0')
		k++;
	(*(*flag)).press = ft_atoi((str + *i + (*(*flag)).j));
	if ((*(*flag)).press == 0)
		(*(*flag)).j += k;
	else
		(*(*flag)).j += ft_numlen(10, (*(*flag)).press) + k;
	if (*(str + *i + (*(*flag)).j) != '%')
		(*(*flag)).zero = 0;
}

static void	check_press(const char *str, va_list args, t_flag *flag, int *i)
{
	if (*(str + *i + (*flag).j) == '.')
	{
		(*flag).j++;
		if (*(str + *i + (*flag).j) == '*')
		{
			(*flag).press = va_arg(args, int);
			(*flag).j++;
			if ((*flag).press >= 0 && *(str + *i + (*flag).j) != '%')
				(*flag).zero = 0;
		}
		else if (ft_isdigit(*(str + *i + (*flag).j)))
			check_press_num(str, &flag, i);
		else
		{
			if (*(str + *i + (*flag).j) != '%')
				(*flag).zero = 0;
			(*flag).press = 0;
		}
	}
}

int	check_flags(const char *str, va_list args, int *i)
{
	t_flag	flag;

	init_struct(&flag);
	check_sin_zero(str, &flag, i);
	check_width(str, args, &flag, i);
	check_press(str, args, &flag, i);
	return (print_type(str, args, i, flag));
}
