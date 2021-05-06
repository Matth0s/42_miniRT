/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 03:21:18 by mmoreira          #+#    #+#             */
/*   Updated: 2021/05/05 11:56:28 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../includes/miniRT.h"

static void	sp_intersection_III(double *t)
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
		if (t[1] < t[0] && t[1] > 0)
			t[0] = t[1];
	}
	if (t[0] < 0 || delta < 0)
		t[0] = 0;
}

static void	sp_intersection_II( t_sp *sp, t_ray *ray, double *t)
{
	t_vet	vet[2];
	double	a;
	double	b;
	double	c;

	a = vet_dot(ray->drct, ray->drct);
	vet[0] = vet_mult_div(ray->drct, 2, 1);
	vet[1] = vet_sum_sub(ray->orig, sp->orig, 0);
	b = vet_dot(vet[0], vet[1]);
	vet[0] = vet_sum_sub(ray->orig, sp->orig, 0);
	vet[1] = vet_sum_sub(ray->orig, sp->orig, 0);
	c = vet_dot(vet[0], vet[1]) - pow((sp->diam) / 2, 2);
	t[0] = a;
	t[1] = b;
	t[2] = c;
}

void	sp_intersection_I( t_sp *sp, t_ray *ray)
{
	t_vet	v1;
	double	t[3];

	sp_intersection_II(sp, ray, t);
	sp_intersection_III(t);
	if (t[0] > 0 && t[0] < ray->t)
	{
		ray->t = t[0];
		v1 = vet_mult_div(ray->drct, ray->t, 1);
		ray->hit = vet_sum_sub(ray->orig, v1, 1);
		ray->norm = vet_sum_sub(ray->hit, sp->orig, 0);
		vet_norm(&ray->norm);
		if (vet_dot(ray->norm, ray->drct) > 0)
			ray->norm = vet_mult_div(ray->norm, -1, 1);
		v1 = vet_mult_div(ray->norm, EPSILON, 1);
		ray->hit = vet_sum_sub(ray->hit, v1, 1);
		ray->color = sp->color;
	}
}
