/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elem_I.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 03:07:10 by mmoreira          #+#    #+#             */
/*   Updated: 2022/02/17 22:34:49 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	check_objs_ii(t_list *lst, int i)
{
	while (lst)
	{
		if (((t_pl *)lst->vol)->type == PLANE)
			if (!(check_obj_pl((t_pl *)lst->vol, i)))
				return (0);
		if (((t_sp *)lst->vol)->type == SPHERE)
			if (!(check_obj_sp((t_sp *)lst->vol, i)))
				return (0);
		if (((t_sq *)lst->vol)->type == SQUARE)
			if (!(check_obj_sq((t_sq *)lst->vol, i)))
				return (0);
		if (((t_tr *)lst->vol)->type == TRIANGLE)
			if (!(check_obj_tr((t_tr *)lst->vol, i)))
				return (0);
		if (((t_cy *)lst->vol)->type == CYLINDER)
			if (!(check_obj_cy((t_cy *)lst->vol, i)))
				return (0);
		lst = lst->next;
		i++;
	}
	return (1);
}

int	check_objs_i(t_mundo *mundo)
{
	t_list	*lst;
	int		i;

	if (!(mundo->o))
		return (error_print_i(1, 0));
	i = 1;
	lst = mundo->objs;
	return (check_objs_ii(lst, i));
}

int	check_cams(t_mundo *mundo)
{
	t_list	*lst;
	t_cam	*cam;
	int		i;

	if (!(mundo->c) && !(mundo->rt))
		return (error_print_i(7, 0));
	i = 1;
	lst = mundo->cams;
	while (lst)
	{
		cam = (t_cam *)lst->vol;
		if (cam->ang < 0 || cam->ang > 180)
			return (error_print_i(8, i));
		if (!(sqrt(vet_dot(cam->drct, cam->drct))))
			return (error_print_i(9, i));
		else
			vet_norm(&cam->drct);
		lst = lst->next;
		i++;
	}
	return (1);
}

int	check_lamps(t_mundo *mundo)
{
	t_list	*lst;
	t_lamp	*lamp;
	int		i;

	if (mundo->l)
	{
		lst = mundo->lamps;
		i = 1;
		while (lst)
		{
			lamp = (t_lamp *)lst->vol;
			if (lamp->forc < 0 || lamp->forc > 1)
				return (error_print_i(5, i));
			if (!(check_color(lamp->color)))
				return (error_print_i(6, i));
			lst = lst->next;
			i++;
		}
	}
	else
		ft_printf("Tu ta ligado que não boto lampada no bagulho né?\n");
	return (1);
}

int	check_screan_abnt(t_mundo *mundo)
{
	if (!(mundo->rsl[2]))
		return (error_print_i(1, 0));
	if (!(mundo->a))
		return (error_print_i(2, 0));
	if (mundo->ablig.forc < 0 || mundo->ablig.forc > 1)
		return (error_print_i(3, 0));
	if (!(check_color(mundo->ablig.color)))
		return (error_print_i(4, 0));
	return (1);
}
