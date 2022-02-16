/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:29:28 by mmoreira          #+#    #+#             */
/*   Updated: 2021/09/20 10:13:57 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	calc_start(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (i < ft_strlen(set))
	{
		if (*(char *)(s1 + j) == *(set + i))
		{
			j += 1;
			i = 0;
		}
		else
			i++;
	}
	return (j);
}

static unsigned int	calc_end(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = ft_strlen(s1);
	while (i < ft_strlen(set))
	{
		if (*(char *)(s1 + j - 1) == *(set + i))
		{
			j -= 1;
			i = 0;
		}
		else
			i++;
	}
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	if (!(s1) || !(set))
		return (NULL);
	k = 0;
	while (k < ft_strlen(s1) && (ft_strchr(set, *(s1 + k))))
		k++;
	if (k == ft_strlen(s1))
		return (ft_substr(s1, 0, 0));
	i = calc_start(s1, set);
	j = calc_end(s1, set);
	return (ft_substr(s1, i, j - i));
}
