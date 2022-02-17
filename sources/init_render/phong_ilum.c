/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_ilum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 03:43:34 by mmoreira          #+#    #+#             */
/*   Updated: 2022/02/17 19:09:03 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vet	color_ambiente(t_abnt abnt)
{
	t_vet	color;

	vet_color_norm(&abnt.color, 1);
	color = vet_mult(abnt.color, abnt.forc);
	return (color);
}

t_vet	color_difuse(t_ray *ray, t_ray light)
{
	t_vet	color;
	double	t;

	t = vet_dot(ray->norm, light.drct) * light.forc;
	color = vet_mult(light.color, t);
	return (color);
}

t_vet	color_especular(t_ray *ray, t_ray light)
{
	t_vet	reflex;
	t_vet	color;
	double	t;

	t = vet_dot(ray->norm, light.drct) * 2;
	reflex = vet_sub(vet_mult(ray->norm, t), light.drct);
	vet_norm(&reflex);
	t = -vet_dot(ray->drct, reflex);
	if (t < 0)
		return (vet_create(0, 0, 0));
	t = pow(t, C_ESPECULAR) * light.forc;
	color = vet_mult(light.color, t);
	return (color);
}
