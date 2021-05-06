/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_mundo_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 02:23:41 by mmoreira          #+#    #+#             */
/*   Updated: 2021/04/27 01:48:19 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

int	check_info(char **info, int n)
{
	int	i;

	i = 0;
	while (*(info + i) != NULL)
		i++;
	if (i != n)
		return (0);
	return (1);
}

int	num_comma(char *info)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_strchr(info, ',');
	while (str && ++i)
		str = ft_strchr(str + 1, ',');
	return (i);
}

int	make_double(char *str, double *n)
{
	int	i;

	i = 0;
	if (*(str + i) == '-')
		i++;
	while (ft_isdigit(*(str + i)))
		i++;
	if (*(str + i) == '.')
	{
		i++;
		while (ft_isdigit(*(str + i)))
			i++;
	}
	if (i == (int)ft_strlen(str))
		*n = ft_atod(str);
	else
		return (0);
	return (1);
}

int	make_vet(char *info, t_vet *vet)
{
	char	**nums;
	int		i;

	if (num_comma(info) != 2)
		return (0);
	i = 0;
	nums = ft_split(info, ',');
	while (*(nums + i) != NULL)
		i++;
	if (i != 3)
	{
		ft_free_split(nums);
		return (0);
	}
	if (!(make_double(*(nums), &vet->x))
		|| !(make_double(*(nums + 1), &vet->y))
		|| !(make_double(*(nums + 2), &vet->z)))
	{
		ft_free_split(nums);
		return (0);
	}
	ft_free_split(nums);
	return (1);
}
