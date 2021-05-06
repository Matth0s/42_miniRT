/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elem_II.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 03:08:17 by mmoreira          #+#    #+#             */
/*   Updated: 2021/04/27 01:48:32 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

int	check_obj_cy(t_cy *cylinder, int i)
{
	if (!(sqrt(vet_dot(cylinder->norm, cylinder->norm))))
		return (error_print_II(5, i));
	else
		vet_norm(&cylinder->norm);
	if (cylinder->diam < 0)
		return (error_print_II(2, i));
	if (cylinder->heig < 0)
		return (error_print_II(3, i));
	if (!(check_color(cylinder->color)))
		return (error_print_II(4, i));
	return (1);
}

int	check_obj_tr(t_tr *triangle, int i)
{
	if (!(sqrt(vet_dot(triangle->norm, triangle->norm))))
		return (error_print_II(7, i));
	else
		vet_norm(&triangle->norm);
	if (!(check_color(triangle->color)))
		return (error_print_II(4, i));
	return (1);
}

int	check_obj_sq(t_sq *square, int i)
{
	if (!(sqrt(vet_dot(square->norm, square->norm))))
		return (error_print_II(5, i));
	else
		vet_norm(&square->norm);
	if (square->side < 0)
		return (error_print_II(6, i));
	if (!(check_color(square->color)))
		return (error_print_II(4, i));
	return (1);
}

int	check_obj_sp(t_sp *sphere, int i)
{
	if (sphere->diam < 0)
		return (error_print_II(2, i));
	if (!(check_color(sphere->color)))
		return (error_print_II(4, i));
	return (1);
}

int	check_obj_pl(t_pl *plane, int i)
{
	if (!(sqrt(vet_dot(plane->norm, plane->norm))))
		return (error_print_II(5, i));
	else
		vet_norm(&plane->norm);
	if (!(check_color(plane->color)))
		return (error_print_II(4, i));
	return (1);
}
