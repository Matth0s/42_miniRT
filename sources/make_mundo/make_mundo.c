/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_mundo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 02:17:34 by mmoreira          #+#    #+#             */
/*   Updated: 2022/02/17 06:23:09 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	set_element(char **info, t_mundo *mundo)
{
	char	*str;

	str = *(info);
	if (*(str) == 'R' && ft_strlen(str) == 1)
		return (set_screen(info, mundo));
	else if (*(str) == 'A' && ft_strlen(str) == 1)
		return (set_abnt(info, mundo));
	else if (*(str) == 'l' && ft_strlen(str) == 1)
		return (set_lamps(info, mundo));
	else if (*(str) == 'c' && ft_strlen(str) == 1)
		return (set_cams(info, mundo));
	else if (*(str) == 'r' && *(str + 1) == 't' && ft_strlen(str) == 2)
		return (set_rotation(info, mundo));
	else if (*(str) == 'p' && *(str + 1) == 'l' && ft_strlen(str) == 2)
		return (set_plane(info, mundo));
	else if (*(str) == 's' && *(str + 1) == 'p' && ft_strlen(str) == 2)
		return (set_sphere(info, mundo));
	else if (*(str) == 's' && *(str + 1) == 'q' && ft_strlen(str) == 2)
		return (set_square(info, mundo));
	else if (*(str) == 't' && *(str + 1) == 'r' && ft_strlen(str) == 2)
		return (set_triangle(info, mundo));
	else if (*(str) == 'c' && *(str + 1) == 'y' && ft_strlen(str) == 2)
		return (set_cylinder(info, mundo));
	else
		return (0);
	return (1);
}

static int	check_line(char *line, t_mundo *mundo)
{
	char	**info;
	int		i;

	if (*line == '\0')
		return (1);
	info = ft_split(line, ' ');
	if (*info == NULL)
		return (0);
	i = set_element(info, mundo);
	ft_free_split(info);
	return (i);
}

int	make_mundo(char *file, t_mundo *mundo)
{
	char	*line;
	int		fd;
	int		i;

	i = 1;
	line = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	while (i == 1)
	{
		i = get_next_line(fd, &line);
		if (i == -1 || !(check_line(line, mundo)))
		{
			free(line);
			close(fd);
			return (0);
		}
		free(line);
	}
	close(fd);
	return (1);
}
