/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cy_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 03:20:22 by mmoreira          #+#    #+#             */
/*   Updated: 2022/02/17 21:54:34 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	cy_intersection_iii(t_cy *cy, t_ray *ray, double t)
{
	t_vet	hit;
	t_vet	v1;
	t_vet	v2;

	hit = vet_sum(ray->orig, vet_mult(ray->drct, t));
	v1 = vet_sub(hit, cy->orig);
	v2 = vet_sum(cy->orig, vet_mult(cy->norm, cy->heig));
	v2 = vet_sub(hit, v2);
	if (vet_dot(cy->norm, v1) >= 0 && vet_dot(cy->norm, v2) <= 0)
		return (1);
	return (0);
}

static void	cy_intersection_ii( t_cy *cy, t_ray *ray, double *t)
{
	double	delta;
	double	a;
	double	b;
	double	c;

	a = t[0];
	b = t[1];
	c = t[2];
	delta = pow(b, 2) - 4 * a * c;
	if (delta == 0)
	{
		if ((-b) / (2 * a) > 0)
			t[0] = (-b) / (2 * a);
	}
	else if (delta > 0)
	{
		t[0] = (-b + sqrt(delta)) / (2 * a);
		t[1] = (-b - sqrt(delta)) / (2 * a);
		if (t[1] < t[0] && t[1] > 0 && cy_intersection_iii(cy, ray, t[1]))
			t[0] = t[1];
	}
	if (!(cy_intersection_iii(cy, ray, t[0])) || t[0] < 0 || delta < 0)
		t[0] = 0;
}

static void	cy_intersection_i( t_cy *cy, t_ray *ray, double *t)
{
	t_vet	vetx;
	double	v[3];
	double	a;
	double	b;
	double	c;

	vetx = vet_sub(ray->orig, cy->orig);
	v[0] = vet_dot(ray->drct, ray->drct);
	v[1] = pow(vet_dot(ray->drct, cy->norm), 2);
	a = v[0] - v[1];
	v[0] = vet_dot(ray->drct, vetx);
	v[1] = vet_dot(ray->drct, cy->norm);
	v[2] = vet_dot(vetx, cy->norm);
	b = 2 * (v[0] - v[1] * v[2]);
	v[0] = vet_dot(vetx, vetx);
	v[1] = vet_dot(vetx, cy->norm);
	c = v[0] - pow(v[1], 2) - pow(cy->diam / 2, 2);
	t[0] = a;
	t[1] = b;
	t[2] = c;
}

void	cy_intersection( t_cy *cy, t_ray *ray)
{
	t_vet	v1;
	double	t[3];
	double	m;

	cy_intersection_i(cy, ray, t);
	cy_intersection_ii(cy, ray, t);
	if (t[0] > 0 && t[0] < ray->t)
	{
		ray->t = t[0];
		v1 = vet_mult(ray->drct, ray->t);
		ray->hit = vet_sum(ray->orig, v1);
		m = vet_dot(cy->norm, ray->hit) - vet_dot(cy->orig, cy->norm);
		v1 = vet_sum(cy->orig, vet_mult(cy->norm, m));
		ray->norm = vet_sub(ray->hit, v1);
		vet_norm(&ray->norm);
		if (vet_dot(ray->norm, ray->drct) > 0)
			ray->norm = vet_mult(ray->norm, -1);
		v1 = vet_mult(ray->norm, EPSILON);
		ray->hit = vet_sum(ray->hit, v1);
		ray->color = cy->color;
	}
}
