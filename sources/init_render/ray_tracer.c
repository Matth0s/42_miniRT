/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 03:38:03 by mmoreira          #+#    #+#             */
/*   Updated: 2022/02/17 22:34:49 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_vet	pixel_drct(t_mundo *mundo, t_view view, int x, int y)
{
	t_vet	drct;
	t_vet	v_right;
	t_vet	v_down;
	double	x1;
	double	y1;

	x1 = (double)(x + 0.5) / mundo->rsl[0];
	y1 = (double)(y + 0.5) / mundo->rsl[1];
	v_right = vet_mult(view.mat.c1, x1);
	v_down = vet_mult(view.mat.c2, -y1);
	drct = vet_sum(v_right, v_down);
	drct = vet_sum(view.init, drct);
	drct = vet_sub(drct, view.cam.orig);
	vet_norm(&drct);
	return (drct);
}

static t_ray	set_ray_primary(t_mundo *mundo, t_view view, int x, int y)
{
	t_ray	ray;

	ray.drct = pixel_drct(mundo, view, x, y);
	ray.orig = view.cam.orig;
	ray.t = INFINITY;
	return (ray);
}

static t_ray	set_ray_secondary(t_ray *ray, t_lamp lamp)
{
	t_ray	light;

	light.drct = vet_sub(lamp.orig, ray->hit);
	light.orig = ray->hit;
	light.t = sqrt(vet_dot(light.drct, light.drct));
	vet_norm(&light.drct);
	light.forc = lamp.forc;
	light.color = lamp.color;
	vet_color_norm(&light.color, 1);
	return (light);
}

static void	color_shadow(t_ray *ray, t_lamp *lamp, t_list *objs, t_vet *color)
{
	t_ray	light;
	double	t;

	light = set_ray_secondary(ray, *lamp);
	t = light.t;
	set_intersection(objs, &light);
	if (light.t == t)
	{
		*color = vet_sum(*color, color_difuse(ray, light));
		*color = vet_sum(*color, color_especular(ray, light));
	}
}

t_vet	raytracer(t_mundo *mundo, t_view view, int x, int y)
{
	t_list	*lst;
	t_ray	ray;
	t_vet	color;

	color = vet_create(0, 0, 0);
	ray = set_ray_primary(mundo, view, x, y);
	set_intersection(mundo->objs, &ray);
	if (ray.t != INFINITY)
	{
		color = vet_sum(color, color_ambiente(mundo->ablig));
		lst = mundo->lamps;
		while (lst)
		{
			color_shadow(&ray, (t_lamp *)lst->vol, mundo->objs, &color);
			lst = lst->next;
		}
		vet_color_norm(&ray.color, 1);
		color = vet_color_mult(ray.color, color);
		vet_color_norm(&color, 0);
	}
	return (color);
}
