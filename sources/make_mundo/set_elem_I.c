/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_elem_I.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 02:28:30 by mmoreira          #+#    #+#             */
/*   Updated: 2022/02/17 22:34:49 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	set_screen(char **info, t_mundo *mundo)
{
	int	i;

	if (!(check_info(info, 3)) || mundo->rsl[2] == 1)
		return (0);
	i = 0;
	while (ft_isdigit(*(*(info + 1) + i)))
		i++;
	if (i == (int)ft_strlen(*(info + 1)))
		mundo->rsl[0] = ft_atoi(*(info + 1));
	else
		return (0);
	i = 0;
	while (ft_isdigit(*(*(info + 2) + i)))
		i++;
	if (i == (int)ft_strlen(*(info + 2)))
		mundo->rsl[1] = ft_atoi(*(info + 2));
	else
		return (0);
	mundo->rsl[2] = 1;
	return (1);
}

int	set_abnt(char **info, t_mundo *mundo)
{
	if (!(check_info(info, 3)) || mundo->a == 1)
		return (0);
	if (!(make_double(*(info + 1), &mundo->ablig.forc)))
		return (0);
	if (!(make_vet(*(info + 2), &mundo->ablig.color)))
		return (0);
	mundo->a = 1;
	return (1);
}

int	set_lamps(char **info, t_mundo *mundo)
{
	t_lamp	*lamp;

	if (!(check_info(info, 4)))
		return (0);
	lamp = (t_lamp *)malloc(sizeof(t_lamp));
	if (!(lamp))
		return (0);
	if (!(make_vet(*(info + 1), &lamp->orig))
		|| !(make_double(*(info + 2), &lamp->forc))
		|| !(make_vet(*(info + 3), &lamp->color)))
	{
		free(lamp);
		return (0);
	}
	ft_lstadd_back(&mundo->lamps, ft_lstnew(lamp));
	mundo->l += 1;
	return (1);
}

int	set_cams(char **info, t_mundo *mundo)
{
	t_cam	*cam;

	if (!(check_info(info, 4)))
		return (0);
	cam = (t_cam *)malloc(sizeof(t_cam));
	if (!(cam))
		return (0);
	if (!(make_vet(*(info + 1), &cam->orig))
		|| !(make_vet(*(info + 2), &cam->drct))
		|| !(make_double(*(info + 3), &cam->ang)))
	{
		free(cam);
		return (0);
	}
	ft_lstadd_back(&mundo->cams, ft_lstnew(cam));
	mundo->c += 1;
	return (1);
}
