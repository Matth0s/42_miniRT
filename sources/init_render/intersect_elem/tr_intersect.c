/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tr_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 03:20:47 by mmoreira          #+#    #+#             */
/*   Updated: 2022/02/17 21:49:34 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	tr_intersection_ii(t_vet norm, t_vet hit, t_vet v1, t_vet v2)
{
	t_vet	left;
	t_vet	right;
	t_vet	cross;

	left = vet_sub(hit, v1);
	right = vet_sub(v2, v1);
	cross = vet_cross(left, right);
	if (vet_dot(norm, cross) > 0)
		return (1);
	return (0);
}

static int	tr_intersection_i( t_tr *tr, t_ray *ray, double t)
{
	t_vet	hit;

	hit = vet_sum(ray->orig, vet_mult(ray->drct, t));
	if ((tr_intersection_ii(tr->norm, hit, tr->p1, tr->p2)
			&& tr_intersection_ii(tr->norm, hit, tr->p2, tr->p3)
			&& tr_intersection_ii(tr->norm, hit, tr->p3, tr->p1))
		|| (tr_intersection_ii(tr->norm, hit, tr->p1, tr->p3)
			&& tr_intersection_ii(tr->norm, hit, tr->p3, tr->p2)
			&& tr_intersection_ii(tr->norm, hit, tr->p2, tr->p1)))
		return (1);
	return (0);
}

void	tr_intersection( t_tr *tr, t_ray *ray)
{
	t_vet	v1;
	double	i[3];
	double	t;

	if (vet_dot(tr->norm, ray->drct))
	{
		if (vet_dot(tr->norm, ray->drct) > 0)
			tr->norm = vet_mult(tr->norm, -1);
		i[0] = vet_dot(tr->norm, ray->orig);
		i[1] = vet_dot(tr->norm, tr->p1);
		i[2] = vet_dot(tr->norm, ray->drct);
		t = (i[1] - i[0]) / i[2];
		if (t > 0 && t < ray->t && (tr_intersection_i(tr, ray, t)))
		{
			ray->t = t;
			ray->norm = tr->norm;
			v1 = vet_mult(ray->drct, ray->t);
			ray->hit = vet_sum(ray->orig, v1);
			v1 = vet_mult(ray->norm, EPSILON);
			ray->hit = vet_sum(ray->hit, v1);
			ray->color = tr->color;
		}
	}
}
