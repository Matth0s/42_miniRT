/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_ilum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 03:43:34 by mmoreira          #+#    #+#             */
/*   Updated: 2021/04/27 01:48:45 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

t_vet	color_ambiente(t_abnt abnt)
{
	t_vet	color;

	vet_color_norm(&abnt.color, 1);
	color = vet_mult_div(abnt.color, abnt.forc, 1);
	return (color);
}

t_vet	color_difuse(t_ray *ray, t_ray light)
{
	t_vet	color;
	double	t;

	t = vet_dot(ray->norm, light.drct) * light.forc;
	color = vet_mult_div(light.color, t, 1);
	return (color);
}

t_vet	color_especular(t_ray *ray, t_ray light)
{
	t_vet	reflex;
	t_vet	color;
	double	t;

	t = vet_dot(ray->norm, light.drct) * 2;
	reflex = vet_sum_sub(vet_mult_div(ray->norm, t, 1), light.drct, 0);
	vet_norm(&reflex);
	t = -vet_dot(ray->drct, reflex);
	if (t < 0)
		return (vet_create(0, 0, 0));
	t = pow(t, C_ESPECULAR) * light.forc;
	color = vet_mult_div(light.color, t, 1);
	return (color);
}
