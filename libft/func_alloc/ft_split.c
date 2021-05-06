/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:42:32 by mmoreira          #+#    #+#             */
/*   Updated: 2021/04/20 02:42:46 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*sep_clear(char const *s, char c)
{
	char	*temp;
	int		i;
	int		j;

	i = 1;
	j = 0;
	temp = ft_strdup(s);
	if (!(s))
		return (NULL);
	if (ft_strlen(s) == 0)
		return (temp);
	if (*(char *)(s) != c && *(char *)(s) != '\0')
		*(temp + j++) = *(char *)s;
	while (*(char *)(s + i) != '\0')
	{
		if (*(char *)(s + i) == c && *(char *)(s + i - 1) != c)
			*(temp + j++) = c;
		else if (*(char *)(s + i) != c)
			*(temp + j++) = *(char *)(s + i);
		i++;
	}
	*(temp + j) = '\0';
	return (temp);
}

static char	**make_strs(char **s_temp, char *temp, char c)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (*(temp + j) != '\0')
	{
		i = 0;
		while (*(temp + j + i) != c && *(temp + j + i) != '\0')
			i++;
		if (i != 0)
		{
			*(s_temp + k) = ft_substr((char const *)(temp + j), 0, i);
			if (!(*(s_temp + k)))
				return (NULL);
			j += i;
			k++;
		}
		else
			j++;
	}
	return (s_temp);
}

static int	len_s_temp(char *temp, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_strlen(temp) == 0)
		return (j);
	while (*(temp + i) != '\0')
		if (*(temp + i++) == c)
			j++;
	if (*(temp + i - 1) != c)
		j++;
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char	*temp;
	char	**s_temp;
	size_t	j;

	if (!(s))
		return (NULL);
	temp = sep_clear(s, c);
	if (!(temp))
		return (NULL);
	j = len_s_temp(temp, c);
	s_temp = malloc((j + 1) * sizeof(char *));
	if (!(s_temp))
		return (NULL);
	*(s_temp + j) = NULL;
	if (j != 0)
	{
		s_temp = make_strs(s_temp, temp, c);
		if (!(s_temp))
			return (NULL);
	}
	free(temp);
	return (s_temp);
}
